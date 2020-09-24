#include <wiringpi.h>

int main()
{
  wiringPiSetup();			// Setup the library
  pinMode(27, OUTPUT);		// Configure GPIO0 as an output

  // Main program loop
  while(1)
  {
    // Toggle the LED
    digitalWrite(27, HIGH);
    delay(500);
    digitalWrite(27, LOW);
    delay(500);
  }
  return 0;
}
