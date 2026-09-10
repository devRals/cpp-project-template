#include <iostream>
#include <my_cool_class.h>

int main(int argc, char *argv[]) {
  HelloWorld hello_world_object;

  std::cout << hello_world_object.say_hello() << "\n";
}
