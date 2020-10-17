#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

static int fd;
char buf[50];

int main(){
  errno=0;
  //lecture sur le fichier tmp/mychar
  if((fd=open("/tmp/mychar",O_RDONLY))==-1)
    printf("open : %s\n",strerror(errno));
  if(read(fd,buf,20)==-1)
    printf("read : %s\n",strerror(errno));
  close(fd);
  printf("string recieved : %s\n",buf);
  //lecture sur le fichier tmp/mychar1
  /*if((fd=open("/tmp/mychar1",O_RDONLY))==-1)
    printf("open : %s\n",strerror(errno));
  if(read(fd,buf,20)==-1)
    printf("read : %s\n",strerror(errno));
  close(fd);
  printf("string recieved : %s\n",buf);*/
  return 0;
}
