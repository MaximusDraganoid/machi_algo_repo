//
// Created by mmaslov on 07.12.2021.
//
#include "util_function.h"
#include <iostream>

int max(int a, int b) {
    return a < b ? b : a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void printLine() {
    std::cout << "***********************************" << std::endl;
}

void print(unsigned short int* array, unsigned int len) {
    std::cout << "Len is " << len << std::endl;
    for (int i = 0; i < len; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}