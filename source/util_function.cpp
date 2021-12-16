//
// Created by mmaslov on 07.12.2021.
//
#include "../headers/util_function.h"
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

//функция поиска нулей в старших разрядах
int findZeros(unsigned short *array, unsigned int len) {
    int count = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (array[i] != 0) {
            break;
        } else {
            count++;
        }
    }
    return count;
}
