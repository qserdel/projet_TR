#include "mcc.hpp"

using namespace std;
void scan(char choice)
{

    int fd;

    fd = wiringPiI2CSetup(GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR);
    int speed = 100; // Entre 0 et 255
    int pin_ = 0x0FFF;
    int cmd = (speed << 8) | (pin_ & 0xFF00);


    switch(choice){
    case 'r':
        wiringPiI2CWriteReg16(fd, CMD_CW, cmd);
        sleep(1);
        wiringPiI2CWriteReg16(fd, CMD_CW, cmd);
        sleep(1);
        wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
        sleep(1);
        wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
        break;
    case 'l':
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
    }

}

int main(int argc, char* argv[])
{
    for (int i=0; i<10; i++){
        scan(*argv[1]);
        //delay(1);
    }
    scan('s');
}