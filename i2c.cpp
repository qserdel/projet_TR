#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <unistd.h>

using namespace std;

float getDistance(){
  int fd = wiringPiI2CSetup(0x04);
  if (wiringPiI2CWrite (fd, 0x30+1) < 0)
    return (-1) ;
  int value = (int)wiringPiI2CReadReg16(fd,0x30+1);
  float voltage = value*3.3/1024;
  close(fd);
  float distance = -79*voltage*voltage + 143*voltage + 2,4 //valable entre 5 et 80 cm
  return distance;
}

int main()
{
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
