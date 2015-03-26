#include "stdafx.h"
#include "binary_string.h"

bool binary_string::is_correct(const char * const str) const { 
  const char *ptr = str;
  while(*ptr != '\0') {
    if(*ptr != '1' && *ptr != '0') {
      return false;
    }
    ++ptr;
  }
  return true;
}

long binary_string::to_long() const { 
  long result = strtol(c_str(), nullptr, 2);
  return result;
}

void binary_string::set(long number) {
  const long buff_size = sizeof(long) * 8;
  char buffer[buff_size + 1];
  buffer[buff_size] = '\0';
  char *ptr = buffer + buff_size - 1;

  for (long i = buff_size - 1; i >= 0; i--) {
    *ptr-- = (number & 1) + '0';
    number >>= 1;
  }
  ptr = buffer;
  while(*ptr != '1') { 
    ++ptr;
  }
  set(ptr);
}

binary_string::binary_string() {
  set("");
}

binary_string::binary_string(const char * const str) {
  set(str);
}

binary_string::binary_string(const char str) {
  const char cs[2] = { str, '\0' };
  set(cs);
}

binary_string::binary_string(const binary_string& str) {
  basic_string::set(str);
}

void binary_string::set(const char * const str) {
  if(is_correct(str)) {
    basic_string::set(str);
  } else {
    throw uncorrect_value();
  }
}

binary_string binary_string::operator+(const binary_string& str) const {
  long first = to_long();
  long second = str.to_long();
  long result = first + second;
  binary_string s;
  s.set(result);
  return s;
}

binary_string binary_string::operator-(const binary_string& str) const {
  long first = to_long();
  long second = str.to_long();
  long result = first - second;
  binary_string s;
  s.set(result);
  return s;
}

binary_string binary_string::operator^(const binary_string& str) const {
  long first = to_long();
  long second = str.to_long();
  long result = first ^ second;
  binary_string s;
  s.set(result);
  return s;
}