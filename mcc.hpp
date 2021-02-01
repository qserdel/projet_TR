#ifndef MOTOR_CC_HPP
#define MOTOR_CC_HPP

#include <wiringPiI2C.h>
#include <math.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR         0x14

#define GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR         0x14
#define GROVE_MOTOR_DRIVER_I2C_CMD_BRAKE            0x00
#define GROVE_MOTOR_DRIVER_I2C_CMD_STOP             0x01
#define GROVE_MOTOR_DRIVER_I2C_CMD_CW               0x02  // commande tourner dans le sens horaire
#define GROVE_MOTOR_DRIVER_I2C_CMD_CCW              0x03  // anti-horaire
#define GROVE_MOTOR_DRIVER_I2C_CMD_STANDBY          0x04
#define GROVE_MOTOR_DRIVER_I2C_CMD_NOT_STANDBY      0x05
#define GROVE_MOTOR_DRIVER_I2C_CMD_STEPPER_RUN      0x06
#define GROVE_MOTOR_DRIVER_I2C_CMD_STEPPER_STOP     0x07
#define GROVE_MOTOR_DRIVER_I2C_CMD_STEPPER_KEEP_RUN 0x08
#define GROVE_MOTOR_DRIVER_I2C_CMD_SET_ADDR         0x11

void* scan(void *arg);

#endif