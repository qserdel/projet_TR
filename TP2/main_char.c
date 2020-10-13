#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

static int fd;
char* buf;
char* buf1="Hello World!";

int main(){
  errno=0;
  if((fd=open("/dev/mychar",'r'))==-1)
    printf("open : %s\n",strerror(errno));
  if(ioctl(fd,IOC_OUT)==-1)
    printf("ioctl : %s\n",strerror(errno));
  close(fd);
  if((fd=open("/dev/mychar",'w'))==-1)
    printf("open : %s\n",strerror(errno));
  if(write(fd,buf1,12)==-1)
    printf("write : %s\n",strerror(errno));
  close(fd);
  if((fd=open("/dev/mychar",'r'))==-1)
    printf("open : %s\n",strerror(errno));
  if(read(fd,buf,12)==-1)
    printf("read : %s\n",strerror(errno));
  close(fd);
  printf(buf);
  return 0;
}
