#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>

static int fd;

int main(){
  fd=open("/dev/mychar",'w');
  if(fd==-1)
    printf("error in fopen");
  ioctl(fd,TIOCMODG);
  return 0;
}
