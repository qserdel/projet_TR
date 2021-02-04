#include "mcc.hpp"

using namespace std;

// void* balayage(void* arg)
// {
//     int fd;
//     fd = wiringPiI2CSetup(GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR);
//     int speed = 100; // Entre 0 et 255
//     int pin_ = 0x0FFF;
//     int cmd = (speed << 8) | (pin_ & 0xFF00);

//     while(1){
//     //switch(choice){
//     //case 'r':
//         wiringPiI2CWriteReg16(fd, CMD_CW, cmd);
//         sleep(1);
//         wiringPiI2CWriteReg16(fd, CMD_CW, cmd);
//         sleep(1);
//         wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
//         sleep(1);
//         wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
//         //break;
//     /*case 'l':
//         wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
//         sleep(1);
//         wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
//         sleep(1);
//         wiringPiI2CWriteReg16(fd, CMD_CW, cmd);
//         sleep(1);
//         wiringPiI2CWriteReg16(fd, CMD_CW, cmd);
//         break;
//     case 'b':
//         wiringPiI2CWriteReg16(fd, CMD_BRAKE, 0x00);
//         break;
//     case 's':
//         wiringPiI2CWriteReg16(fd, CMD_STOP, 0x00);
//         break;
//     }*/
//     }

//     wiringPiI2CWriteReg16(fd, CMD_STOP, 0x00);
//     return 0;
// }

// void* getPos(void* arg)
// {
//     char buf[20];
//     static int fde;
//     int compteur;
    
//     if((fde=open("/dev/encodeur",O_RDWR))==-1)
//         printf("open : %s\n",strerror(errno));

//     while(1){
//         read(fde,buf,20);
//         sscanf(buf, "%d", &compteur);
//         printf("Position: %d\n",compteur);
//     }
//     close(fde);
//     return 0;
// }

int main(){
    int fd;
    fd = wiringPiI2CSetup(GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR);
    wiringPiI2CWriteReg16(fd, CMD_STOP, 0x00);
    return 0;
}