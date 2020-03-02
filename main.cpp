#include <iostream>

#include "interpreter.hpp"

int main(int argc, char** argv)
{
  if(argc != 2)
  {
    std::cout << "Usage: " << argv[0] <<  " source_file" << std::endl;
  }
  else 
  {
    Interpreter interpreter(argv[1]);
    interpreter.run();
  }
  return 0;
}