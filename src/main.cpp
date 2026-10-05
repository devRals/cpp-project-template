#include "hello.h"
#include <iostream>

int main(int argc, char *argv[]) {
  HelloWorld hello_world_object;

  std::cout << hello_world_object.say_hello() << std::endl;
}
