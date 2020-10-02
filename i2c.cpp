#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
  std::cout<<wiringPiI2CRead(0)<<endl; 
  return 0;
}
