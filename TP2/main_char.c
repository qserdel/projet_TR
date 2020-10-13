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
    printf("open : %s\n",strerror(errno));
  if(ioctl(fd,IOC_OUT)==-1)
    printf("ioctl : %s\n",strerror(errno));
  close(fd);
  fd=open("/dev/mychar",'w');
  if(fd==-1)
    printf("open : %s\n",strerror(errno));
  if(write(fd,buf,12)==-1)
    printf("write : %s\n",strerror(errno));
  close(fd);
  fd=open("/dev/mychar",'r');
  if(fd==-1)
    printf("open : %s\n",strerror(errno));
  if(read(fd,buf,12)==-1)
    printf("read : %s\n",strerror(errno));
  close(fd);
  printf(buf);
  return 0;
}
