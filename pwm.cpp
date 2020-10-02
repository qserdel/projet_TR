#include <wiringPi.h>
#include <softPwm.h>

//pour faire bouger les servo d'avant en arriere

int main()
{
wiringPiSetup();			// Setup the library
softPwmCreate(5,100,200); //initialise  pin 16 en pwm
softPwmCreate(25,100,200); //initialise pin 18 en pwm

while(1)
{
	for(int i = 0; i < 200; i++)
	{
		softPwmWrite(5, i);
		softPwmWrite(25, i);
		delay(10);
	}
	for(int i = 200; i > 0; i--)
  {
    softPwmWrite(5, i);
		softPwmWrite(25, i);
    delay(10);
  }
}
return 0;
}
