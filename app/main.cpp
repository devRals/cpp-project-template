#include "cool_lib.h"
#include <iostream>

using namespace cool_lib;

int main(void) {
  const char *red = "\x1b[35m";

  HelloWorld hewwo_uwu;
  std::cout << red << hewwo_uwu.greet() << std::endl;
}
