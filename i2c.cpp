#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
  uint16_t data [1];
  int fd = wiringPiI2CSetup(0x04);
  if (wiringPiI2CWrite (fd, 0x30+1) < 0)
    return (-1) ;
  while(1){
    read (fd, data, 1);
    cout<<(int)data[1]<<endl;
    delay(20);
    }
  /*while(1){
    cout<<wiringPiI2CRead(fd)<<endl;
    delay(10);
  }*/
  return 0;
}

/*{
  wiringPiSetup();
  pinMode(2, INPUT);		// Configure GPIO06 as an output
  while(1){
    cout<<digitalRead(2)<<endl;
    delay(50);
  }
  return 0;

}*/
