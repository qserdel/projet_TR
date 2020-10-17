#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

static int fd;

int main(){

  errno=0;
  if((fd=open("/dev/mychar",O_WRONLY))==-1)
    printf("open : %s\n",strerror(errno));
  if(write(fd,"",12)==-1)
    printf("write : %s\n",strerror(errno));
  close(fd);
  return 0;
}
