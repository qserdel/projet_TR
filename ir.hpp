#ifndef IR_HPP
#define IR_HPP

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <unistd.h>

static int i2c_pin = 1;

using namespace std;


/*thread de recuperation de la distance mesurée par le capteur et affichage dans le terminal*/
void *getDistance(void* arg){
  while(1){
    int fd = wiringPiI2CSetup(0x04);
    if (wiringPiI2CWrite (fd, 0x30+i2c_pin) < 0)
      return (NULL) ;
    int value = (int)wiringPiI2CReadReg16(fd,0x30+i2c_pin);
    //approximation de la distance mesurée en fonction de l'intensité mesurée
    float voltage = value*3.3/1024;
    close(fd);
    float distance = (17*voltage*voltage -75*voltage + 90); //valable entre 5 et 80 cm
    cout<<"Distance : " <<distance<<endl;
  }
  return 0; 

}

#endif