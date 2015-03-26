#define long long long
#include "stdafx.h"
#include "basic_string.h"

class binary_string : public basic_string { // бинарная строка
private:
  bool is_correct(const char * const str) const;
public:
  binary_string();
  binary_string(const char * const str);
  binary_string(const char str);
  binary_string(const binary_string& str);

  long to_long() const;
  void set(long number);
  void set(const char * const str);

  // переопределение опреаций
  binary_string operator+(const binary_string& str) const; // сложение
  binary_string operator-(const binary_string& str) const; // вычитание
  binary_string operator^(const binary_string& str) const; // XOR
  class uncorrect_value : public std::exception {
  public:
    virtual const char * what() const throw(){
      return "Uncorrect value for binary string";
    }
  };
};