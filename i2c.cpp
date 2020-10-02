#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <cerrno>
#include <stdlib>
using namespace std;

int main()
{
  int fd = wiringPiI2CSetup(0x04);
  if(fd==-1){
    cout<<strerror(errno)<<endl;
  };
  //while(1){
    cout<<wiringPiI2CRead(fd)<<endl;
    if(wiringPiI2CRead(fd)==-1){
      cout<<strerror(errno)<<endl;
    };
    delay(50);
  //}
  return 0;
}
