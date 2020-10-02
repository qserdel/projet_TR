#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
  uint8_t data [100];
  int fd = wiringPiI2CSetup(0x04);
  while ((read (fd, data, 2) < 0)){
    delay (20) ;
  }
  for(int i=0;i<100;i++){
    cout<<(int)data[i]<<endl;
  }
  return 0;
}

/*{
  wiringPiSetup();
  pinMode(2, INPUT);		// Configure GPIO06 as an output
  while(1){
    cout<<digitalRead(2)<<endl;
    delay(50);
  }
  return 0;

}*/
