//
// Created by max on 16.12.2021.
//

#include "../headers/math_func.h"
#include "../headers/util_function.h"

//size of result array is sizeOfArray or sizeOfArray + 1.
//сложение чисел одной длины
unsigned short int *plus(unsigned short int firstArray[],
                         unsigned short int secondArray[],
                         unsigned short int sizeOfSummation,
                         unsigned short int &resultSize) {

    resultSize = sizeOfSummation;
    unsigned short int *resultArray = new unsigned short int[resultSize];
    for (int i = 0; i < resultSize; i++) {
        resultArray[i] = 0;
    }

    int buff_res = 0;
    unsigned short int perenos = 0;
    for (int i = 0; i < resultSize; i++) {
        buff_res = firstArray[i] + secondArray[i] + perenos;
        perenos = 0;
        if (buff_res >= OSN) {
            perenos = 1;
            buff_res -= OSN;
        }
        resultArray[i] = buff_res;
    }

    if (perenos == 1) {

        unsigned short int *buff = new unsigned short int[resultSize];
        for (int i = 0; i < resultSize; i++) {
            buff[i] = resultArray[i];
        }

        resultArray = new unsigned short int[resultSize + 1];
        for (int i = 0; i < resultSize; i++) {
            resultArray[i] = buff[i];
        }

        resultArray[resultSize] = 1;
        resultSize = resultSize + 1;
    }

    return resultArray;
}
