#include <iostream>		// Include all needed libraries here
#include <wiringPi.h>

using namespace std;		// No need to keep using “std”

int main()
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
}
