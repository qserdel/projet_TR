#include <iostream>		// Include all needed libraries here
#include <wiringPi.h>

using namespace std;		// No need to keep using “std”

int main()
{
wiringPiSetup();			// Setup the library
pinMode(5, OUTPUT);		// Configure GPIO0 as an output

// Main program loop
while(1)
{
// Toggle the LED
digitalWrite(5, !digitalRead(5));
delay(500);
}

return 0;
}
