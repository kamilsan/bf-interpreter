#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class CodeParser
{
public:
  CodeParser(const std::string& sourceFile): position_(0)
  {
    std::ifstream codeFileStream(sourceFile);
    std::stringstream codeStream;
    codeStream << codeFileStream.rdbuf();
    code_ = codeStream.str();
    codeFileStream.close();
  }

  char peek() const
  {
    return code_[position_];
  }

  bool end() const
  {
    return position_ == code_.size();
  }

  bool pos() const
  {
    return position_;
  }

  char consume()
  {
    return code_[position_++];
  }

  void unget()
  {
    position_--;
  }
private:
  std::string code_;
  unsigned int position_;
};

int main(int argc, char** argv)
{
  if(argc != 2)
  {
    printf("Usage: %s source_file\n", argv[0]);
    return 0;
  }

  CodeParser code{argv[1]};

  int tape[30000] = {0};
  int ptr = 0;

  while(!code.end())
  {
    char command = code.consume();
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
        while(!code.end())
        {
          char c = code.consume();
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
        code.unget();
        code.unget();
        while(code.pos() > 0)
        {
          char c = code.peek();
          if(c == ']')
            nesting++;
          else if(c == '[')
          {
            nesting--;
            if(nesting == 0)
            {
              code.consume();
              break;
            }
          }
          code.unget();
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