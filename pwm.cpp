#include <wiringPi.h>
#include <softPwm.h>

//pour faire bouger les servo d'avant en arriere

int main()
{
wiringPiSetup();			// Setup the library
softPwmCreate(27,0,100); //initialise un pin pwm

while(1)
{
	for(int i = 0; i < 100; i++)
	{
		softPwmWrite(27, i);
		delay(10);
	}
	for(int i = 100; i > 0; i--)
  {
    softPwmWrite(27, i);
    delay(10);
  }
}
return 0;
}
