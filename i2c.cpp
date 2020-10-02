#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <cerrno>
using namespace std;

int main()
{
  if(wiringPiI2CSetup(0x04)==-1){
    cout<<strerror(errno)<<endl;
  };
  //while(1){
    cout<<wiringPiI2CRead(0x04)<<endl;
    if(wiringPiI2CRead(0x04)==-1){
      cout<<strerror(errno)<<endl;
    };
    delay(50);
  //}
  return 0;
}
