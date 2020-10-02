#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream.h>

int main()
{
  cout<<wiringPiI2CRead(0)<<std;
  return 0;
}
