#include <iostream>		// Include all needed libraries here
#include <wiringPi.h>

using namespace std;		// No need to keep using “std”

/*int main()
{
wiringPiSetup();			// Setup the library
pinMode(21, OUTPUT);		// Configure GPIO0 as an output

// Main program loop
while(1)
{
// Toggle the LED
digitalWrite(21, HIGH);
delay(500);
digitalWrite(21, LOW);
delay(500);
}

return 0;
}*/

unsigned int prevTime;		// Temporary variable that holds the previous millis value

int main()
{
wiringPiSetup();			// Setup the library
pinMode(26, PWM_OUTPUT);		// Configure GPIO1 as an output for PWM

// Main program loop
while(1)
{
	for(int i = 0; i < 1024; i++)
	{
		pwmWrite(26, i);
		delay(1);
	}
}
return 0;
}
