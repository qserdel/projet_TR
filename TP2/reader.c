#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <linux/wait.h>

static int fd;
char buf[50];

int main(){
  errno=0;
  if((fd=open("/dev/mychar",O_RDONLY))==-1)
    printf("open : %s\n",strerror(errno));
  if(read(fd,buf,12)==-1)
    printf("read : %s\n",strerror(errno));
  close(fd);
  printf("string recieved : %s\n",buf);
  return 0;
}
