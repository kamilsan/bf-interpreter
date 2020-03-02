#pragma once

#include <string>

class Scanner
{
public:
  Scanner(const std::string& sourceFile);

  char peek() const;
  bool end() const;
  bool pos() const;

  char consume();
  void unget();
private:
  std::string code_;
  unsigned int position_;
};