#include <iostream>

#include "scanner.hpp"

int main(int argc, char** argv)
{
  if(argc != 2)
  {
    printf("Usage: %s source_file\n", argv[0]);
    return 0;
  }

  Scanner scanner{argv[1]};

  int tape[30000] = {0};
  int ptr = 0;

  while(!scanner.end())
  {
    char command = scanner.consume();
    if(command == '+')
    {
      tape[ptr] += 1;
    }
    else if(command == '-')
    {
      tape[ptr] -= 1;
    }
    else if(command == '.')
    {
      putchar(tape[ptr]);
    }
    else if(command == '>')
    {
      ptr += 1;
    }
    else if(command == '<')
    {
      ptr -= 1;
    }
    else if(command == '[')
    {
      if(tape[ptr] == 0)
      {
        int nesting = 1;
        while(!scanner.end())
        {
          char c = scanner.consume();
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
      if(tape[ptr] != 0)
      {
        int nesting = 1;
        scanner.unget();
        scanner.unget();
        while(scanner.pos() > 0)
        {
          char c = scanner.peek();
          if(c == ']')
            nesting++;
          else if(c == '[')
          {
            nesting--;
            if(nesting == 0)
            {
              scanner.consume();
              break;
            }
          }
          scanner.unget();
        }
      }
    }
    else if(command == ',')
    {
      tape[ptr] = getchar();
    }
  }

  return 0;
}