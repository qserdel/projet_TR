#include <wiringPi.h>
#include <softPwm.h>

//pour faire bouger les servo d'avant en arriere

int main()
{
wiringPiSetup();			// Setup the library
softPwmCreate(27,100,200); //initialise un pin pwm

while(1)
{
	for(int i = 0; i < 200; i++)
	{
		softPwmWrite(27, i);
		delay(10);
	}
	for(int i = 200; i > 0; i--)
  {
    softPwmWrite(27, i);
    delay(10);
  }
}
return 0;
}
