#include <wiringPi.h>

int main()
{
  wiringPiSetup();			// Setup the library
  pinMode(21, OUTPUT);		// Configure GPIO05 as an output
  pinMode(22, OUTPUT);		// Configure GPIO06 as an output

  // Main program loop
  while(1)
  {
    // Toggle the LED
    digitalWrite(21, HIGH);
    digitalWrite(22, LOW);
    delay(500);
    digitalWrite(21, LOW);
    digitalWrite(22, HIGH);
    delay(500);
  }
  return 0;
}
