#include "stdafx.h"

class basic_string { // базовый класс строка
private:
  char *string;
  int size;
  char * strcpy(char *dest, const char * const src, int length);
public:
  basic_string();
  basic_string(const basic_string& str);
  basic_string(const char * const str);
  basic_string(const char c);
  basic_string& operator=(const basic_string& str);
  basic_string& operator=(const char * const str);
  basic_string& operator=(const char c);
  virtual void set(const char * const str);
  void set(const basic_string& str);
  void set(const char c);
  int length() const;
  const char * const c_str() const;
  inline void empty();
  char& operator[](int index);
  char operator[](int index) const;
  friend std::ostream& operator <<(std::ostream& stream, const basic_string& str);
  friend std::istream& operator >>(std::istream& stream, basic_string& str);
  virtual ~basic_string();
};
