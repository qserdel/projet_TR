#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>

static int fd;

int main(){
  void* buf;
  errno=0;
  fd=open("/dev/mychar",'r');
  if(fd==-1)
    printf(strerror(errno));
  ioctl(fd,IOC_OUT);
  close(fd);
  fd=open("/dev/mychar",'w');
  if(fd==-1)
    printf(strerror(errno));
  write(fd,"Hello World!");
  close(fd);
  fd=open("/dev/mychar",'r');
  if(fd==-1)
    printf(strerror(errno));
  read(fd,buf,12);
  close(fd);
  printf(*buf);
  return 0;
}
