#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>

using namespace std;

int main()
{
  int fd = wiringPiI2CSetup(0x04);
  while ((read (fd, data, 2) < 0))
    delay (10) ;
  }
  return 0;
}
