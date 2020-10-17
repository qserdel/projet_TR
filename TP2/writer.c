#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

static int fd;

int main(){

  errno=0;
  //ecriture sur le fichier tmp/mychar
  if((fd=open("/tmp/mychar",O_WRONLY))==-1)
    printf("open : %s\n",strerror(errno));
  if(write(fd,"Hello mychar0!",20)==-1)
    printf("write : %s\n",strerror(errno));
  close(fd);
  //ecriture sur le fichier tmp/mychar1
  if((fd=open("/tmp/mychar1",O_WRONLY))==-1)
    printf("open : %s\n",strerror(errno));
  if(write(fd,"Hello mychar1!",20)==-1)
    printf("write : %s\n",strerror(errno));
  close(fd);
  return 0;
}
