#include <wiringPi.h>

int main(void)
{
    // Red LED: Physical pin 18, BCM GPIO24, and WiringPi pin 5.
    const int led = 5;

    wiringPi.Setup();

    wiringPi.pinMode(led, OUTPUT);

    while (1) {
        digitalWrite(led, HIGH);
        delay(5000);
        digitalWrite(led, LOW);
        delay(5000);
    }

    return 0;
}
