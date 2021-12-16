//
// Created by max on 16.12.2021.
//

#include "../headers/math_func_big_osn.h"
#include "../headers/util_function.h"

//сложение чисел одной длины
unsigned short int *plusBigOsn(unsigned short int firstArray[],
                         unsigned short int secondArray[],
                         unsigned short int sizeOfSummation,
                         unsigned short int &resultSize) {

    resultSize = sizeOfSummation;
    unsigned short int *resultArray = new unsigned short int[resultSize];
    for (int i = 0; i < resultSize; i++) {
        resultArray[i] = 0;
    }

    unsigned buff_res = 0;
    unsigned short int perenos = 0;
    for (int i = 0; i < resultSize; i++) {
        buff_res = firstArray[i] + secondArray[i] + perenos;
        perenos = buff_res>> SHIFT;
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
