#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
using namespace std;

int main()
{
  if(wiringPiI2CSetup(0x04)==-1){
    cout<<"c'est de la merde"<<std::endl;
  };
  while(1){
    cout<<wiringPiI2CRead(0x04)<<std::endl;
    delay(50);
  }
  return 0;
}
