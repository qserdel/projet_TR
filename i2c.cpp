#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <unistd.h>

static int i2c_pin = 1;

using namespace std;

float getDistance(){

  int fd = wiringPiI2CSetup(0x04);
  if (wiringPiI2CWrite (fd, 0x30+i2c_pin) < 0)
    return (-1) ;
  int value = (int)wiringPiI2CReadReg16(fd,0x30+i2c_pin);
  float voltage = value*3.3/1024;
  close(fd);
  float distance = (31.43*voltage*voltage -119.3*voltage + 111.8); //valable entre 5 et 80 cm
  //cout<<voltage<<endl;
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
