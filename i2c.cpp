#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
  uint8_t data [5];
  int fd = wiringPiI2CSetup(0x04);
  while ((read (fd, data, 2) < 0)){
    delay (10) ;
  }
  for(int i=0;i<5;i++){
    cout<<data[i]<<endl;
  }
  return 0;
}
