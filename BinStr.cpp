// BinStr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binary_string.h"

void print_menu() {
    std::cout <<
    "1 - set string" << std::endl <<
    "2 - string difference" << std::endl <<
    "3 - check for more" << std::endl <<
    "4 - check for less" << std::endl <<
    "5 - view strings" << std::endl <<
    "6 - exit" << std::endl;
}

binary_string& choosestring(binary_string *strings[], int num) {
    int index;
    while(true) {
        std::cout << "input index:" << std::endl;
        std::cin >> index;
        if(index < num && index >= 0) {
            break;
        }
    }
    return *strings[index];
}

int main(int argc, const char *argv[]) {
    const int num = 6;
    basic_string *strings[num];
    char input_buff[2048];
    char input_wish;
    
    std::cout << "input strings:" << std::endl;
    
    for(int i = 0; i < num; i++) {
        std::cin >> input_buff;
        strings[i] = new binary_string(input_buff);
    }
    
    while(true) {
        print_menu();
        std::cout << "enter your wish:" << std::endl;
        std::cin >> input_wish;
        switch(input_wish) {
            case '1': {
                binary_string& str = choosestring(((binary_string**)strings), num);
                std::cout << "input string" << std::endl;
                std::cin >> input_buff;
                str = input_buff;
                break;
            }
            case '2': {
                std::cout << "choose index of first string:" << std::endl;
                binary_string& str1 = choosestring(((binary_string**)strings), num);
                std::cout << "choose index of second string:" << std::endl;
                binary_string& str2 = choosestring(((binary_string**)strings), num);
                std::cout << (str1 - str2) << std::endl;
                break;
            }
            case '3': {
                std::cout << "choose index of first string:" << std::endl;
                binary_string& str1 = choosestring(((binary_string**)strings), num);
                std::cout << "choose index of second string:" << std::endl;
                binary_string& str2 = choosestring(((binary_string**)strings), num);
                std::cout << (str1 + str2) << std::endl;
                break;
            }
            case '4': {
                std::cout << "choose index of first string:" << std::endl;
                binary_string& str1 = choosestring(((binary_string**)strings), num);
                std::cout << "choose index of second string:" << std::endl;
                binary_string& str2 = choosestring(((binary_string**)strings), num);
                std::cout << (str1 ^ str2) << std::endl;
                break;
            }
            case '5':
                for(int i = 0; i < num; i++) {
                    std::cout << (*strings[i]) << std::endl;
                }
                break;
            case '6':
                return 0;
            default:
                std::cout << "error" << std::endl;
        }
    }
    return 0;
}