//
// Created by mmaslov on 07.12.2021.
//

#ifndef UNTITLED_MATH_FUNC_H
#define UNTITLED_MATH_FUNC_H

//сложение чисел одинаковой длины
unsigned short int *plus(unsigned short int firstArray[],
                         unsigned short int secondArray[],
                         unsigned short int sizeOfSummation,
                         unsigned short int &resultSize);

//умножение чисел одинаковой длины
unsigned short int *multiply(unsigned short int firstArray[],
                             unsigned short int secondArray[],
                             unsigned short int sizeOfSummation,
                             unsigned short int &resultSize);

//вычитание чисел одинаковой длины
unsigned short int *minus(unsigned short int firstArray[],
                          unsigned short int secondArray[],
                          unsigned short int sizeOfDifferences);

//сравнение двух чисел одинаковой длины
int compare(unsigned short int firstArray[],
            unsigned short int secondArray[],
            unsigned short int sizeOfSummation);

//сравнение двух чисел разной длины
int compare(unsigned short int firstArray[],
            unsigned short int secondArray[],
            unsigned short int firstSize,
            unsigned short int secondSize);

//умножение длинного числа на короткое
unsigned short int* multipleByShort(unsigned short int *a,
                                    unsigned int lenA,
                                    unsigned short int multiplier,
                                    unsigned int &resultLen);

// a div b
unsigned short int* schoolDivision_quotient(unsigned short int *a, unsigned int lenA,
                                            unsigned short int *b, unsigned int lenB, unsigned int &resLen);

#endif //UNTITLED_MATH_FUNC_H
