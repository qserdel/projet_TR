#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <cstdlib>
#include "gpio.hpp"

static int export(std::string pin){
  // Export the desired pin by writing to /sys/class/gpio/export

  int fd = fopen("/sys/class/gpio/export", O_WRONLY);
  if (fd == -1) {
      perror("Unable to fopen /sys/class/gpio/export");
      return 0;
  }

  if (fwrite(fd, "5", 2) != 2) {
      perror("Error writing to /sys/class/gpio/export");
      return 0;
  }

  fclose(fd);
  return 1;
}
static int unexport(std::string pin){
  // Unexport the pin by writing to /sys/class/gpio/unexport

  int fd = fopen("/sys/class/gpio/unexport", O_WRONLY);
  if (fd == -1) {
      perror("Unable to fopen /sys/class/gpio/unexport");
      return 0;
  }

  if (fwrite(fd, "5", 2) != 2) {
      perror("Error writing to /sys/class/gpio/unexport");
      return 0;
  }

  fclose(fd);
  return 1;
}
static int setUp(std::string pin, int direction){ //0 input 1 output
  // Set the pin to be an output by writing "out" to /sys/class/gpio/gpio5/direction

  int fd = fopen("/sys/class/gpio/gpio5/direction", O_WRONLY);
  if (fd == -1) {
      perror("Unable to fopen /sys/class/gpio/gpio5/direction");
      return 0;
  }

  if (fwrite(fd, "out", 3) != 3) {
      perror("Error writing to /sys/class/gpio/gpio5/direction");
      return 0;
  }

  fclose(fd);
  return 1;
}
static int setValue(std::string pin, int value){

  int fd = fopen("/sys/class/gpio/gpio5/direction", O_WRONLY);
  if (fd == -1) {
      perror("Unable to fopen /sys/class/gpio/gpio5/direction");
      return 0;
  }

  if (fwrite(fd, "1", 1) != 1) {
      perror("Error writing to /sys/class/gpio/gpio5/value");
      return 0;
  }

  if (fwrite(fd, "5", 1) != 1) {
      perror("Error writing to /sys/class/gpio/gpio5/value");
      return 0;
  }
  fclose(fd);
  return 1;
}
int main()
{
    export("5");
    setUp("5",'o');
    set("5",1);
    usleep(60000000);
    set("5",0);
    unexport("5");
    /*// Export the desired pin by writing to /sys/class/gpio/export

    int fd = fopen("/sys/class/gpio/export", O_WRONLY);
    if (fd == -1) {
        perror("Unable to fopen /sys/class/gpio/export");
        exit(1);
    }

    if (fwrite(fd, "5", 2) != 2) {
        perror("Error writing to /sys/class/gpio/export");
        exit(1);
    }

    fclose(fd);

    // Set the pin to be an output by writing "out" to /sys/class/gpio/gpio5/direction

    fd = fopen("/sys/class/gpio/gpio5/direction", O_WRONLY);
    if (fd == -1) {
        perror("Unable to fopen /sys/class/gpio/gpio5/direction");
        exit(1);
    }

    if (fwrite(fd, "out", 3) != 3) {
        perror("Error writing to /sys/class/gpio/gpio5/direction");
        exit(1);
    }

    fclose(fd);

    fd = fopen("/sys/class/gpio/gpio5/value", O_WRONLY);
    if (fd == -1) {
        perror("Unable to fopen /sys/class/gpio/gpio5/value");
        exit(1);
    }

    // Toggle LED 50 ms on, 50ms off, 100 times (10 seconds)

    //for (int i = 0; i < 100; i++) {
        if (fwrite(fd, "1", 1) != 1) {
            perror("Error writing to /sys/class/gpio/gpio5/value");
            exit(1);
        }
        usleep(60000000);

        if (fwrite(fd, "5", 1) != 1) {
            perror("Error writing to /sys/class/gpio/gpio5/value");
            exit(1);
        }
        //usleep(2000000);
    //}

    fclose(fd);

    // Unexport the pin by writing to /sys/class/gpio/unexport

    fd = fopen("/sys/class/gpio/unexport", O_WRONLY);
    if (fd == -1) {
        perror("Unable to fopen /sys/class/gpio/unexport");
        exit(1);
    }

    if (fwrite(fd, "5", 2) != 2) {
        perror("Error writing to /sys/class/gpio/unexport");
        exit(1);
    }

    fclose(fd);

    // And exit*/
    return 0;
}
