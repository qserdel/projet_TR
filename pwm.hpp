#ifndef PMW_HPP
#define PMW_HPP

#include <wiringPi.h>
#include <softPwm.h>

static int pin_m1 = 5; 	//pin gpio24
static int pin_m2 = 25; //pin gpio26

int cam_motors_setup(){
	if(wiringPiSetup()==-1) // Setup the library
		return -1;
	softPwmCreate(pin_m1,90,180); //initialise  pin m1 en pwm
	softPwmCreate(pin_m2,0,90); //initialise pin m2 en pwm
  return 0;
}

void *cam_motors(void *arg)
{
cam_motors_setup();

while(1)
{
	for(int i = 0; i < 180; i++)
	{
		softPwmWrite(pin_m1, i);
		softPwmWrite(pin_m2, i);
		delay(10);
	}
	for(int i = 180; i > 0; i--)
  {
    softPwmWrite(pin_m1, i);
	softPwmWrite(pin_m2, i);
    delay(10);
  }
}
return 0;
}


#endif