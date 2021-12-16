//
// Created by max on 16.12.2021.
//

#ifndef UNTITLED_MATH_FUNC_BIG_OSN_H
#define UNTITLED_MATH_FUNC_BIG_OSN_H


//сложение чисел одинаковой длины
unsigned short int *plusBigOsn(unsigned short int firstArray[],
                         unsigned short int secondArray[],
                         unsigned short int sizeOfSummation,
                         unsigned short int &resultSize);


//умножение чисел разной длины
unsigned short int *multiplyDiffLenBigOsn(unsigned short int firstArray[],
                                    unsigned short int secondArray[],
                                    unsigned short int firstLen,
                                    unsigned short int secondLen,
                                    unsigned short int &resultSize);

//умножение чисел одинаковой длины
unsigned short int *multiplyBigOsn(unsigned short int firstArray[],
                             unsigned short int secondArray[],
                             unsigned short int sizeOfSummation,
                             unsigned short int &resultSize);

//умножение длинного числа на короткое
unsigned short int* multipleByShortBigOsn(unsigned short int *a,
                                    unsigned int lenA,
                                    unsigned short int multiplier,
                                    unsigned int &resultLen);

//вычитание чисел одинаковой длины
unsigned short int *minusBigOsn(unsigned short int firstArray[],
                          unsigned short int secondArray[],
                          unsigned short int sizeOfDifferences);

// a div b
unsigned short int* schoolDivision_quotient_BigOsn(unsigned short int *a, unsigned int lenA,
                                            unsigned short int *b, unsigned int lenB, unsigned int &resLen);

unsigned short int* schoolDivisionLongByShort_quotient_BigOsn(unsigned short int *a, unsigned int lenA,
                                                       unsigned short int b, unsigned int &resLen);

unsigned short int* schoolDivision_quotient_and_remainder_BigOsn(unsigned short int *a, unsigned int lenA,
                                                          unsigned short int *b, unsigned int lenB, unsigned int &resLen);

#endif //UNTITLED_MATH_FUNC_BIG_OSN_H
