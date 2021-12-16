//
// Created by max on 16.12.2021.
//

#include "../headers/math_func_big_osn.h"
#include "../headers/util_function.h"

//умножение длинных чисел разной длины
unsigned short int *multiplyDiffLenBigOsn(unsigned short int firstArray[],
                                    unsigned short int secondArray[],
                                    unsigned short int firstLen,
                                    unsigned short int secondLen,
                                    unsigned short int &resultSize) {
    int buff = 0;
    resultSize = firstLen + secondLen;
    unsigned short int *resultArray = new unsigned short int[resultSize];
    for (int i = 0; i < resultSize; i++) {
        resultArray[i] = 0;
    }

    unsigned short int *perenos = new unsigned short int[resultSize];
    for (int i = 0; i < resultSize; i++) {
        perenos[i] = 0;
    }

    for (int ix = 0; ix < firstLen; ix++) {
        for (int jx = 0; jx < secondLen; jx++) {
            buff = resultArray[ix + jx] + firstArray[ix] * secondArray[jx];
            perenos[ix + jx + 1] += buff >> SHIFT;
            resultArray[ix + jx] = buff;
        }
    }

    //нормалзуем перенос для сложения дальше
    for (int i = 0; i < resultSize - 1; i++) {
        perenos[i + 1] += perenos[i] >> OSN;
        perenos[i] = perenos[i];
    }

    resultArray = plusBigOsn(resultArray, perenos, resultSize, resultSize);
    return resultArray;
}


//умножение длинных чисел одинаковой длины
unsigned short int *multiplyBigOsn(unsigned short int firstArray[],
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
            buff = resultArray[ix + jx] + firstArray[ix] * secondArray[jx];
            if (buff > OSN) {
                perenos[ix + jx + 1] += buff >> SHIFT;
            }
            resultArray[ix + jx] = buff;
        }
    }

    //нормалзуем перенос для сложения дальше
    for (int i = 0; i < resultSize - 1; i++) {
        perenos[i + 1] += perenos[i] >> SHIFT;
        perenos[i] = perenos[i];
    }

    resultArray = plusBigOsn(resultArray, perenos, resultSize, resultSize);
    return resultArray;
}

//a * k
unsigned short int* multipleByShortBigOsn(unsigned short int *a,
                                    unsigned int lenA,
                                    unsigned short int multiplier,
                                    unsigned int &resultLen) {

    resultLen = lenA;
    unsigned short int *result = new unsigned short int[lenA];
    unsigned short int perenos = 0;
    unsigned int buff = 0;
    for (int i = 0; i < lenA; i++) {
        buff = perenos + multiplier * a[i];
        perenos = buff >> SHIFT;
        result[i] = buff;
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
