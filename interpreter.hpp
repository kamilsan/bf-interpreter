#pragma once

#include "scanner.hpp"

#include <stdint.h>

class Interpreter
{
public:
  Interpreter(const std::string& sourceFile);

  void run();
private:
  Scanner scanner_;
  int32_t tape_[30000];
  int ptr_;
};