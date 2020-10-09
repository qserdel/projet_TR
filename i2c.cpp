#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int getDistance(){
  int fd = wiringPiI2CSetup(0x04);
  if (wiringPiI2CWrite (fd, 0x30+1) < 0)
    return (-1) ;
  int distance = (int)wiringPiI2CReadReg16(fd,0x30+1);
  close(fd);
  return distance;
}

int main()
{
  int distance;
  while(1){
    cout<<getDistance()<<endl;
    delay(20);
  }
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
