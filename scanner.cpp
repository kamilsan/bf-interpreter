#include "scanner.hpp"

#include <fstream>
#include <sstream>

Scanner::Scanner(const std::string& sourceFile): position_(0)
{
  std::ifstream codeFileStream(sourceFile);
  std::stringstream codeStream;
  codeStream << codeFileStream.rdbuf();
  code_ = codeStream.str();
  codeFileStream.close();
}

char Scanner::peek() const
{
  return code_[position_];
}

bool Scanner::end() const
{
  return position_ == code_.size();
}

bool Scanner::pos() const
{
  return position_;
}

char Scanner::consume()
{
  return code_[position_++];
}

void Scanner::unget()
{
  position_--;
}