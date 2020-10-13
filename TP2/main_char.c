#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

static int fd;
char* buf;

int main(){
  errno=0;
  fd=open("/dev/mychar",'r');
  if(fd==-1)
    printf(strerror(errno));
  ioctl(fd,IOC_OUT);
  close(fd);
  fd=open("/dev/mychar",'w');
  if(fd==-1)
    printf(strerror(errno));
  printf("%d\n",write(fd,"Hello World!",12));
  close(fd);
  /fd=open("/dev/mychar",'r');
  if(fd==-1)
    printf(strerror(errno));
  printf("%d\n",read(fd,buf,12));
  close(fd);
  printf(buf);
  return 0;
}
