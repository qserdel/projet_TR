#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
using namespace std;

int main()
{
  wiringPiI2CSetup(0x04);
  while(1);
    cout<<wiringPiI2CRead(0x04)<<std::endl;
  return 0;
}
