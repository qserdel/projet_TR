#ifndef MCC_HPP
#define MCC_HPP

#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <math.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pwm.hpp"

#define GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR         0x14
#define CMD_BRAKE            0x00
#define CMD_STOP             0x01
#define CMD_CW               0x02  // commande tourner dans le trigo
#define CMD_CCW              0x03  // anti-horaire / anti-trigo
#define CMD_SET_ADDR         0x11


static int i2c_pin = 1;
static int position = 0;

using namespace std;

static pthread_cond_t c = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;


void *getDistance(void* arg){
  while(1){
    pthread_mutex_lock(&m);
    int fd = wiringPiI2CSetup(0x04);
    if (wiringPiI2CWrite (fd, 0x30+i2c_pin) < 0)
      return (NULL) ;
    int value = (int)wiringPiI2CReadReg16(fd,0x30+i2c_pin);
    float voltage = value*3.3/1024;
    close(fd);
    float distance = (17*voltage*voltage -75*voltage + 90); //valable entre 5 et 80 cm
    if ((distance <40) && (distance>5)){
        cam_motors2(position);
        sleep(1);
    }
    cout<<"Distance : " <<distance<<endl;
    pthread_mutex_unlock(&m2);
    
  }
  return 0; 

}

void* balayage(void* arg)
{
    int fd;
    fd = wiringPiI2CSetup(GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR);
    int speed = 100; // Entre 0 et 255
    int pin_ = 0x0FFF;
    int cmd = (speed << 8) | (pin_ & 0xFF00);

    while(1){
    //switch(choice){
    //case 'r':
        wiringPiI2CWriteReg16(fd, CMD_CW, cmd);
        sleep(1);
        wiringPiI2CWriteReg16(fd, CMD_CW, cmd);
        sleep(1);
        wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
        sleep(1);
        wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
        //break;
    /*case 'l':
        wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
        sleep(1);
        wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
        sleep(1);
        wiringPiI2CWriteReg16(fd, CMD_CW, cmd);
        sleep(1);
        wiringPiI2CWriteReg16(fd, CMD_CW, cmd);
        break;
    case 'b':
        wiringPiI2CWriteReg16(fd, CMD_BRAKE, 0x00);
        break;
    case 's':
        wiringPiI2CWriteReg16(fd, CMD_STOP, 0x00);
        break;
    }*/
    }

    wiringPiI2CWriteReg16(fd, CMD_STOP, 0x00);
    return 0;
}


void* getPos(void* arg)
{
    char buf[20];
    static int fde;
    int offset = 0;
    int compteur =0;

    if((fde=open("/dev/encodeur",O_RDWR))==-1)
        printf("open : %s\n",strerror(errno));
    read(fde,buf,20);
    sscanf(buf, "%d", &offset);
    while(1){
        pthread_mutex_lock(&m2);
        sleep(0.05);
        read(fde,buf,20);
        sscanf(buf, "%d", &compteur);
        position = compteur - offset ;
        printf("Position: %d\n",position);
        
        pthread_mutex_unlock(&m);
        
    }
    close(fde);
    return 0;
}


#endif