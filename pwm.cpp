#include <wiringPi.h>
#include <softPwm.h>

static int pin_m1 = 5; 	//pin gpio24
static int pin_m2 = 25; //pin gpio26

int cam_motors_setup(){
	if(wiringPiSetup()==-1) // Setup the library
		return -1;
	softPwmCreate(pin_m1,0,100); //initialise  pin m1 en pwm
	softPwmCreate(pin_m2,0,100); //initialise pin m2 en pwm
}

//pour faire bouger les servo d'avant en arriere
int main()
{
cam_motors_setup();

while(1)
{
	for(int i = 0; i < 100; i++)
	{
		softPwmWrite(5, i);
		softPwmWrite(25, i);
		delay(10);
	}
	for(int i = 100; i > 0; i--)
  {
    softPwmWrite(5, i);
		softPwmWrite(25, i);
    delay(10);
  }
}
return 0;
}
