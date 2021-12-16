//
// Created by max on 16.12.2021.
//

#include "../headers/math_func.h"
#include "../headers/util_function.h"

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
