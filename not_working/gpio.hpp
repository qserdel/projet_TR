#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <cstdlib>

static class gpio {

public :
  static int export(std::string pin);
  static int unexport(std::string pin);
  static int setUp(std::string pin, int direction){
  static int setValue(std::string pin,int value);

};
