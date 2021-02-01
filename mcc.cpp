#include "mcc.hpp"

void* scan(void *arg)
{
    printf("1\n");
    int fd = wiringPiI2CSetup (GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR);
    int* fd2 = (int*) arg;
    int i = 0;

    char buf2[20];
    double angle, offset;
    double resolution = (double)360/420;
    long compteur;
    char init[10];
 
    read(*fd2, buf2, 20);
    compteur = atoi(buf2);
    offset = compteur;
    
    
    while(1)
    {
        wiringPiI2CWriteReg16(fd,GROVE_MOTOR_DRIVER_I2C_CMD_CW, 0xFF00);
        read(*fd2, buf2, 20);

        compteur = atoi(buf2);
        angle = (compteur - offset) * resolution;
        printf("angle = %lf\n offset = %lf\n", angle, offset);

        sleep(1);
        wiringPiI2CWriteReg16(fd,GROVE_MOTOR_DRIVER_I2C_CMD_STOP, 0x0000);
        sleep(1);
        wiringPiI2CWriteReg16(fd,GROVE_MOTOR_DRIVER_I2C_CMD_CCW, 0xFF00);
        sleep(1);
        wiringPiI2CWriteReg16(fd,GROVE_MOTOR_DRIVER_I2C_CMD_STOP, 0x0000);
        sleep(1);
    }

    return 0;
}

/*
while(1)
    {
        
        if (i < 30)
        {
            
            while (i < 30)
            {
                wiringPiI2CWriteReg16(fd,GROVE_MOTOR_DRIVER_I2C_CMD_STEPPER_KEEP_RUN, 0xFF00);
                read(*fd2, buf2, 20);
                compteur = atoi(buf2);
                angle = (compteur - offset) * resolution;
                printf("1/ angle = %lf\n i = %d\n", angle, i);
                sleep(1);
                i++;
            }
            wiringPiI2CWriteReg16(fd,GROVE_MOTOR_DRIVER_I2C_CMD_STOP, 0x0000);
            sleep(1);
        }

        else if (i < 60) 
        {
            wiringPiI2CWriteReg16(fd,GROVE_MOTOR_DRIVER_I2C_CMD_CCW, 0xA000);
            read(*fd2, buf2, 20);
            compteur = atoi(buf2);
            angle = (compteur - offset) * resolution;
            printf("2/ angle = %lf\n i = %d\n", angle, i);
            sleep(1);
            i++;
        }
        
        else
        {
            wiringPiI2CWriteReg16(fd,GROVE_MOTOR_DRIVER_I2C_CMD_STOP, 0x0000);
            sleep(1);
        }
        
    }
*/