#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

static int fd;
char* buf="Hello World!";

int main(){
  errno=0;
  fd=open("/dev/mychar",'r');
  if(fd==-1)
    printf(strerror(errno)+"\n");
  if(ioctl(fd,IOC_OUT)==-1)
    printf(sterror(errno)+"\n");
  close(fd);
  fd=open("/dev/mychar",'w');
  if(fd==-1)
    printf(strerror(errno)+"\n");
  if(write(fd,"Hello World!",12)==-1)
    printf(strerror(errno)+"\n");
  close(fd);
  fd=open("/dev/mychar",'r');
  if(fd==-1)
    printf(strerror(errno)+"\n");
  if(read(fd,buf,12)==-1))
    printf(strerror(errno)+"\n");
  close(fd);
  printf(buf);
  return 0;
}
