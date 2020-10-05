#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SZ 7

static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
clockid_t clock_send;
clockid_t clock_safe_send;
struct timespec time_send,time_safe_send,time_end_send,time_end_safe_send;

void send_char(char data) {
  double time = (double) random() / RAND_MAX * 8;
  struct timespec t;
  t.tv_sec = time / 1000;
  t.tv_nsec = (int) (time * 1000000) % 1000000000;
  nanosleep(&t, NULL);
  write(1, &data, 1);
}

void send(char *data, size_t len) {
  unsigned i;
  for (i = 0; i < len; i++)
    send_char(data[i]);
}

void safe_send(char *data, size_t len){
  pthread_mutex_lock(&m);
  send(data,len);
  pthread_mutex_unlock(&m);
  }

void *task(void *arg) {
  char *buf = (char *) arg;
  safe_send(buf, SZ);
  return NULL;
}

void *task_test(void *arg) {
  char *buf = (char *) arg;
  send(buf, SZ);
  return NULL;
}

int main(int argc, char **argv) {
  pthread_t id[4];
  int i;
  char msgs[4][SZ] = { "123456", "ABCDEF", "abcdef", "[{()}]" };

  clock_gettime(CLOCK_REALTIME,&time_send);
  for (i = 0; i < 4; i++)
    pthread_create(&id[i], NULL, task_test, msgs[i]);
  for (i = 0; i < 4; i++)
    pthread_join(id[i], NULL);
  clock_gettime(CLOCK_REALTIME,&time_end_send);
  printf("\n");
  printf("temps send: %lf ms\n",(double)(time_end_send.tv_nsec-time_send.tv_nsec)/1000000);


  clock_gettime(CLOCK_REALTIME,&time_safe_send);
  for (i = 0; i < 4; i++)
    pthread_create(&id[i], NULL, task, msgs[i]);
  for (i = 0; i < 4; i++)
    pthread_join(id[i], NULL);
  clock_gettime(CLOCK_REALTIME,&time_end_safe_send);
  printf("\n");
  printf("temps safe send: %lf ms\n",(double)(time_end_safe_send.tv_nsec-time_safe_send.tv_nsec)/1000000);
  pthread_mutex_unlock(&m);
  return 0;
}
