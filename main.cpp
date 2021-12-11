#include <iostream>
#include "impl/math_func.h"

//числа записаны в обратном порядке. Т.е. числов 123 в массиве будет представлено
// как [3, 2, 1].

void test();

int main() {
    unsigned int testNum = 65535;
    unsigned int t = testNum >> 1;
    std::cout << t << std::endl;

    t = testNum << 1;
    std::cout << t << std::endl;

    return 0;
}

void test() {

    unsigned short int firstArray[] = {9, 9, 9, 9, 9};
    unsigned short int secondArray[] = {9, 9, 9, 9, 9};

    //сравнение 2-ух чисел одинаковой длины
    std::cout << compare(firstArray, secondArray, 5) << std::endl;

    //сложение 2-ух чисел одинаковой длины
    unsigned short int resLen = 0;
    unsigned short int *result = plus(firstArray, secondArray, 5, resLen);
    std::cout << "Result of plus. Len is " << resLen << std::endl;
    for (int i = 0; i < resLen; i++) {
        std::cout << result[i] << ' ';
    }
    std::cout << std::endl;

    //разность 2-ух чисел одинаковой длины
    result = minus(firstArray, secondArray, 5);
    std::cout << "Result of minus. Len is " << resLen << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << result[i] << ' ';
    }
    std::cout << std::endl;

    //произведение 2-ух чисел одинаковой длины
    result = multiply(firstArray, secondArray, 5, resLen);
    std::cout << "Result of multiply. Len is " << resLen << std::endl;
    for (int i = 0; i < resLen; i++) {
        std::cout << result[i] << ' ';
    }
    std::cout << std::endl;
}


