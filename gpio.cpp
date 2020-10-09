#include <wiringPi.h>

static int pin_led_r = 21; //gpio05
static int pin_led_v = 22; //gpio06

int led_setUp(){
  if(wiringPiSetup()==-1) // Setup the library
    return -1;
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  return 0;
}

int switch_led(const char led, int state ){
  if(led=='r'){
    if(state==1){
      digitalWrite(21, HIGH);
      return 0;
    }
    digitalWrite(21, LOW);
    return 0;
  }
  if(led=='g'){
    if(state==1){
      digitalWrite(22, HIGH);
      return 0;
    }
    digitalWrite(22, LOW);
    return 0;
  }
  return -1;
}

int main()
{
  led_setUp();

  // Main program loop
  while(1)
  {
    // Toggle the LED
    switch_led('g',1);
    switch_led('r',0);
    delay(500);
    switch_led('g',0);
    switch_led('r',1);
    delay(500);
  }
  return 0;
}
