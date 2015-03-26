#include "stdafx.h"
#include "basic_string.h"

basic_string::basic_string() { // �����������
    set("");
}

basic_string::basic_string(const basic_string& str) { // ����������� �����������
    set(str);
}

basic_string::basic_string(const char * const str) { // ����������� ����������� C-������
    set(str);
}

basic_string::basic_string(const char c) { // ����������� ����������� ���� ������
    set(c);
}

char * basic_string::strcpy(char *dest, const char * const src, int length) { // ����������� 
    for(int i = 0; i < (length == 0 ? strlen(src) : length); ++i) {
        dest[i] = src[i];
    }
    return dest;
}

void basic_string::set(const char * const str) {
    if(str == string) {
        return;
    }
    size = (int)strlen(str);
    string = new char[length() + 1];
    string = strcpy(string, str, length());
    string[length()] = '\0';
}

void basic_string::set(const basic_string& str) {
    if(this == &str) {
        return;
    }
    set(str.c_str());
}

void basic_string::set(const char c) {
    const char str[2] = { c, '\0' };
    set(str);
}

basic_string::~basic_string() { // ����������
    empty();
}

int basic_string::length() const { // �����
    return size;
}

const char * const basic_string::c_str() const {
    return string;
}

void basic_string::empty() {
    if(string) {
        delete[] string;
    }
    size = 0;
}

// ��������������� ��������
basic_string& basic_string::operator=(const basic_string& str) {
    set(str);
    return *this;
}

basic_string& basic_string::operator=(const char * const str) {
    set(str);
    return *this;
}

basic_string& basic_string::operator=(const char c) {
    set(c);
    return *this;
}

char& basic_string::operator[](int index) { // ��������� � ������ 
    return *(string + index);
}

char basic_string::operator[](int index) const { // ��������� � ������ 
    return *(string + index);
}

std::ostream& operator <<(std::ostream& stream, const basic_string& str) { // �������� ����� (�������������)
    stream << str.c_str();
    return stream;
}

std::istream& operator >>(std::istream& stream, basic_string& str) { // �������� ������ (�������������)
    char buffer[4096];
    stream >> buffer;
    return stream;
}