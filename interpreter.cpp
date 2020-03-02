#include "interpreter.hpp"

Interpreter::Interpreter(const std::string& sourceFile):
  scanner_(sourceFile),
  tape_{0},
  ptr_(0)
{}

void Interpreter::run()
{
  while(!scanner_.end())
  {
    char command = scanner_.consume();
    if(command == '+')
    {
      tape_[ptr_] += 1;
    }
    else if(command == '-')
    {
      tape_[ptr_] -= 1;
    }
    else if(command == '.')
    {
      putchar(tape_[ptr_]);
    }
    else if(command == '>')
    {
      ptr_ += 1;
    }
    else if(command == '<')
    {
      ptr_ -= 1;
    }
    else if(command == '[')
    {
      if(tape_[ptr_] == 0)
      {
        int nesting = 1;
        while(!scanner_.end())
        {
          char c = scanner_.consume();
          if(c == '[')
            nesting++;
          else if(c == ']')
          {
            nesting--;
            if(nesting == 0)
              break;
          }
        }
      }
    }
    else if(command == ']')
    {
      if(tape_[ptr_] != 0)
      {
        int nesting = 1;
        scanner_.unget();
        scanner_.unget();
        while(scanner_.pos() > 0)
        {
          char c = scanner_.peek();
          if(c == ']')
            nesting++;
          else if(c == '[')
          {
            nesting--;
            if(nesting == 0)
            {
              scanner_.consume();
              break;
            }
          }
          scanner_.unget();
        }
      }
    }
    else if(command == ',')
    {
      tape_[ptr_] = getchar();
    }
  }
}