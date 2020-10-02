#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>

using namespace std;

int main()
{
  int fd = wiringPiI2CSetup(0x04);
  while(1){
    cout<<wiringPiI2CRead(fd)<<endl;
    delay(50);
  }
  return 0;
}
