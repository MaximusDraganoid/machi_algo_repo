//
// Created by max on 16.12.2021.
//

#include "../headers/math_func.h"

//позволяет сравнивать числа вне зависимости от основания системы счисления
//-1 - больше firstArray, 1 - больше secondArray, 0 - равны

//сравнение чисел одинаковой длины
int compare(unsigned short int firstArray[],
            unsigned short int secondArray[],
            unsigned short int sizeOfSummation) {
    for (int i = sizeOfSummation - 1; i >= 0; i--) {
        if (firstArray[i] == secondArray[i])
            continue;
        if (firstArray[i] > secondArray[i]) {
            return 1;
        } else {
            return -1;
        }
    }
    return 0;
}

//сравнение чисел разной длины
int compare(unsigned short int firstArray[],
            unsigned short int secondArray[],
            unsigned short int firstSize,
            unsigned short int secondSize) {
    if (firstSize > secondSize) {
        return 1;
    }

    if (secondSize > firstSize) {
        return -1;
    }

    return compare(firstArray, secondArray, firstSize);
}
