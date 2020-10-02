#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
  uint8_t data [2];
  int fd = wiringPiI2CSetup(0x04);
  if (wiringPiI2CWrite (fd, 0x10) < 0)
    return (-1) ;
  while(1){
    while ((read (fd, data, 2) < 0)){
      delay (10) ;
    }
    for(int i=0;i<2;i++){
      cout<<(int)data[i]<<endl;
    }
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
