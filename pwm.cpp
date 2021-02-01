#include "pwm.hpp"

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
