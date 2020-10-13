#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

static int fd;
char buf[50];

int main(){
  errno=0;
  //test ioctl
  if((fd=open("/dev/mychar",O_RDWR))==-1)
    printf("open : %s\n",strerror(errno));
  if(ioctl(fd,IOC_OUT)==-1)
    printf("ioctl : %s\n",strerror(errno));
  close(fd);

  //test write read
  if((fd=open("/dev/mychar",O_RDWR))==-1)
    printf("open : %s\n",strerror(errno));
  if(write(fd,"Hello World!",12)==-1)
    printf("write : %s\n",strerror(errno));
  if(read(fd,buf,12)==-1)
    printf("read : %s\n",strerror(errno));
  close(fd);
  printf("string recieved : %s\n",buf);
  return 0;
}
