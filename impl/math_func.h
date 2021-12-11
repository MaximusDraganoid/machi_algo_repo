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

#endif //UNTITLED_MATH_FUNC_H
