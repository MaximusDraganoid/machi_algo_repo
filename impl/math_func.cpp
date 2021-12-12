//
// Created by mmaslov on 07.12.2021.
//
#include "math_func.h"
#include "util_function.h"

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

//-1 - больше firstArray, 1 - больше secondArray, 0 - равны
int compare(unsigned short int firstArray[],
            unsigned short int secondArray[],
            unsigned short int sizeOfSummation) {
    for (int i = sizeOfSummation - 1; i >= 0; i--) {
        if (firstArray[i] == secondArray[i])
            continue;
        if (firstArray[i] > secondArray[i]) {
            return -1;
        } else {
            return 1;
        }
    }
    return 0;
}

//вычитание чисел одинаковой длины (first > second)
unsigned short int *minus(unsigned short int firstArray[],
                          unsigned short int secondArray[],
                          unsigned short int sizeOfDifferences) {

    unsigned short int *resultArray = new unsigned short int[sizeOfDifferences];
    for (int i = 0; i < sizeOfDifferences; i++) {
        resultArray[i] = 0;
    }

    unsigned short int zaem = 0;
    int buf_res = 0;
    for (int i = 0; i < sizeOfDifferences; i++) {
        buf_res = firstArray[i] - secondArray[i] - zaem;
        zaem = 0;
        if (buf_res < 0) {
            zaem = 1;
            buf_res = buf_res + OSN;
        }
        resultArray[i] = buf_res;
    }

    return resultArray;
}


unsigned short int *multiply(unsigned short int firstArray[],
                             unsigned short int secondArray[],
                             unsigned short int sizeOfSummation,
                             unsigned short int &resultSize) {
    int buff = 0;
    resultSize = sizeOfSummation + sizeOfSummation;
    unsigned short int *resultArray = new unsigned short int[resultSize];
    for (int i = 0; i < resultSize; i++) {
        resultArray[i] = 0;
    }

    unsigned short int *perenos = new unsigned short int[resultSize];
    for (int i = 0; i < resultSize; i++) {
        perenos[i] = 0;
    }

    for (int ix = 0; ix < sizeOfSummation; ix++) {
        for (int jx = 0; jx < sizeOfSummation; jx++) {
            buff = resultArray[ix + jx] + firstArray[ix] * firstArray[jx];
            if (buff > OSN) {
                perenos[ix + jx + 1] += buff / OSN;
            }
            resultArray[ix + jx] = buff % OSN;
        }
    }

    //нормалзуем перенос для сложения дальше
    for (int i = 0; i < resultSize - 1; i++) {
        perenos[i + 1] += perenos[i] / OSN;
        perenos[i] = perenos[i] % OSN;
    }

    resultArray = plus(resultArray, perenos, resultSize, resultSize);
    return resultArray;
}

//a * k
unsigned short int* multipleByShort(unsigned short int *a,
                                    unsigned int lenA,
                                    unsigned short int multiplier,
                                    unsigned int &resultLen) {

    resultLen = lenA;
    unsigned short int *result = new unsigned short int[lenA];
    unsigned short int perenos = 0;
    unsigned int buff = 0;
    for (int i = 0; i < lenA; i++) {
        buff = perenos + multiplier * a[i];
        perenos = buff / OSN;
        result[i] = buff % OSN;
    }

    if (perenos) {
        resultLen = resultLen + 1;
        unsigned short int *newResult = new unsigned short int[resultLen];
        for(int i = 0; i < lenA; i++) {
            newResult[i] = result[i];
        }
        newResult[lenA] = perenos;
        result = newResult;
    }

    return result;
}


// a:b
unsigned short int* schoolDivision_quotient(unsigned short int *a, unsigned int lenA,
                                   unsigned short int *b, unsigned int lenB) {
    unsigned short int *result = new unsigned short int[lenA - lenB + 1];


}

unsigned short int* schoolDivision_remainder(unsigned short int *a, unsigned int lenA,
                                            unsigned short int *b, unsigned int lenB) {

}