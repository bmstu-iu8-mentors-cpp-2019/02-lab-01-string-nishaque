// Copyright 2020 Yulia Timoshenko timoshenkojulie01@gmail.com
#include "string.hpp"

String::~String() { delete[] str; }

String::String() {
  str = new char[1];
  str[0] = '\0';
  size = 0;
}

String::String(const String &rhs) {
  size = rhs.size;
  str = new char[size + 1];
  for (size_t i = 0; i < size; i++) {
    str[i] = rhs.str[i];
  }
  str[size] = '\0';
}

String::String(const char *data) {
  size = std::strlen(data);
  str = new char[size + 1];
  for (size_t i = 0; i < size; i++) {
    str[i] = data[i];
  }
  str[size] = '\0';
}

String &String::operator=(const String &rhs) {
  if (this == &rhs) {
    return *this;
  }
  delete[] str;
  size = rhs.size;
  str = new char[size + 1];
  for (size_t j = 0; j < rhs.size; j++) str[j] = rhs.str[j];
  str[rhs.size] = '\0';
  return *this;
}

String &String::operator+=(const String &rhs) {
  size_t i = size;
  char *r = new char[size + rhs.size + 1];
  for (size_t j = 0; j < size; j++) {
    r[j] = str[j];
  }
  for (size_t j = 0; j < rhs.size; j++) {
    r[i + j] = rhs.str[j];
  }
  r[size + rhs.size] = '\0';
  delete[] str;
  str = r;
  size += rhs.size;
  return *this;
}

String &String::operator*=(unsigned int m) {
  char *temp = new char[size * m + 1];
  for (size_t i = 0, t = 0; i < m; ++i, t += std::strlen(str)) {
    std::copy(str, str + std::strlen(str), temp + t);
  }
  size = size * m;
  temp[size] = '\0';
  delete[] str;
  str = temp;
  return *this;
}

bool String::operator==(const String &rhs) const {
  return !std::strcmp(str, rhs.str);
}

bool String::operator<(const String &rhs) const {
  return (std::strcmp(str, rhs.str) < 0);
}

size_t String::Find(const String &substr) const {
  for (size_t i = 0; i < size; i++) {
    size_t j = 0;
    while ((substr.str[j] == str[i + j]) && (j < substr.size)) j++;
    if (j == substr.size) return i;
  }
  return -1;
}

void String::Replace(char oldSymbol, char newSymbol) {
  for (size_t i = 0; i < size; i++) {
    if (str[i] == oldSymbol) str[i] = newSymbol;
  }
}

size_t String::Size() const { return size; }

bool String::Empty() const {
  if (*str == '\0')
    return true;
  else
    return false;
}

char String::operator[](size_t index) const {
  if (index > std::strlen(str)) throw std::out_of_range("index is too big");
  return str[index];
}

char &String::operator[](size_t index) {
  if (index > size) throw std::out_of_range("index is too big");
  return str[index];
}

void String::RTrim(char symbol) {
  size_t k = 0;
  size_t i = size - 1;
  while ((static_cast<int>(i) >= 0) && (str[i] == symbol)) {
    k++;
    i--;
  }
  char *r = new char[size - k + 1];
  for (i = 0; i < size - k; i++) {
    r[i] = str[i];
  }
  r[size - k] = '\0';
  delete[] str;
  str = r;
  size = size - k;
}

void String::LTrim(char symbol) {
  size_t k = 0;
  size_t i = 0;
  while ((i < size) && (str[i] == symbol)) {
    k++;
    i++;
  }
  char *r = new char[size - k + 1];
  for (i = size; i > k - 1; i--) {
    r[i - k] = str[i];
  }
  r[size - k] = '\0';
  delete[] str;
  str = r;
  size = size - k;
}

void String::swap(String &oth) { std::swap(*this, oth); }

std::ostream &operator<<(std::ostream &, const String &);

String operator+(const String &a, const String &b) {
  return String(a) += String(b);
}

String operator*(const String &a, unsigned int b) { return String(a) *= b; }

bool operator!=(const String &a, const String &b) { return !(a == b); }

bool operator>(const String &a, const String &b) { return b < a; }

std::ostream &operator<<(std::ostream &out, const String &str) {
  for (size_t i = 0; i < str.size; i++) {
    out << str.str[i];
  }
  return out;
}
