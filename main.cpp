#include <iostream>
#include "impl/math_func.h"

//числа записаны в обратном порядке. Т.е. числов 123 в массиве будет представлено
// как [3, 2, 1].

void test();
void testMultiplyLenByShort();
void testSchoolDivision_quotient();

int main() {

    testSchoolDivision_quotient();
    return 0;
}

//tests:
//63678 : 59 = 1079 (17) - true
//unsigned short int a[] = {8, 7, 6, 3, 6};
//unsigned int lenA = 5;
//unsigned short int b[] = { 9 , 5};
//unsigned int lenB = 2;

//63678 : 598 = 106 (290) - true
//unsigned short int a[] = {8, 7, 6, 3, 6};
//unsigned int lenA = 5;
//unsigned short int b[] = {8, 9 , 5};
//unsigned int lenB = 3;

//63678 : 131 = 486 (12) - true
//3678 : 32 = 114 (30) - true
//3678 : 31 = 118 (20) - true
//3678 : 132 = 27(114) - true
//9999:99 = 101 (0) - true

//63678 : 9 = 7075(3) - true
//unsigned short int a[] = {8, 7, 6, 3, 6};
//unsigned int lenA = 5;
//unsigned short int b[] = { 9 };
//unsigned int lenB = 1;

void testSchoolDivision_quotient() {
//    unsigned short int a[] = {8, 7, 6, 3, 6};
//    unsigned int lenA = 5;
//    unsigned short int b[] = {1, 3, 1};
//    unsigned int lenB = 3;
    unsigned int resultLen = 0;

    unsigned short int* result = schoolDivision_quotient(a, lenA, b, lenB, resultLen);

    std::cout << "Result of division. Len is " << resultLen << std::endl;
    for (int i = 0; i < resultLen; i++) {
        std::cout << result[i] << ' ';
    }
    std::cout << std::endl;

}

void testMultiplyLenByShort() {
    unsigned short int firstArray[] = {9, 9, 9, 9, 9};
    unsigned int resultLen = 0;
    unsigned short int multiplier = 5;
    unsigned short int *result =  multipleByShort(firstArray, 5, multiplier, resultLen);

    std::cout << "Result of multiply. Len is " << resultLen << std::endl;
    for (int i = 0; i < resultLen; i++) {
        std::cout << result[i] << ' ';
    }
    std::cout << std::endl;
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


