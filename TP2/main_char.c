#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>

static int fd;

int main(){
  errno=0;
  fd=open("~/../../dev/mychar",'r');
  if(fd==-1)
    printf(strerror(errno));
  ioctl(fd,IOC_OUT);
  return 0;
}
