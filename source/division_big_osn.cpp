//
// Created by max on 16.12.2021.
//

#include "../headers/math_func_big_osn.h"
#include "../headers/math_func.h"
#include "../headers/util_function.h"


#include <iostream>

//функция поиска нулей в старших разрядах
int findZeros(unsigned short *array, unsigned int len) {
    int count = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (array[i] != 0) {
            break;
        } else {
            count++;
        }
    }
    return count;
}

// a:b
//todo: нужно каким-либо образом предсказывать длину частного и остатка
//todo: пока вместо выделения конкретного объема памяти, мы выделим буферы определенных размеров
//todo: затем будем их либо увеличивать либо уменьшать
unsigned short int* schoolDivision_quotient(unsigned short int *a, unsigned int lenA,
                                            unsigned short int *b, unsigned int lenB, unsigned int &resLen) {
    //случай, если делитель больше делимго
    if (lenA < lenB) {
        resLen = 1;
        return new unsigned short int{0};
    }

    //случай, если числа одинаковой длины
    if (lenA == lenB) {
        int comparison = compare(a, b, lenA);
        //случай, когда делитель больше делимого
        if (comparison < 0) {
            resLen = 1;
            return new unsigned short int{0};
        }

        //случай, когда делитель равен делимому
        if (comparison == 0) {
            resLen = 1;
            return new unsigned short int{1};
        }
    }

    resLen = lenA;
    unsigned short int* result = new unsigned short int[lenA];
    for (int i = 0; i < resLen; i++) {
        result[i] = 0;
    }

    unsigned short int* current = new unsigned short int[lenB];
    for (int i = 0; i < lenB; i++) {
        current[lenB - i - 1] = a[lenA - i - 1];
    }

    unsigned int currentLen = lenB;
    int count = 0;

    int i = lenA - 1;
    unsigned int countOfShiftInResult = 0;

    while (compare(current, b, currentLen, lenB) >= 0
           || lenA - lenB - 1 - count <= lenA) {
        countOfShiftInResult++;
        printLine();

        unsigned short int x = 0;
        unsigned short int l = 0, r = BIG_OSN;

        print(result, resLen);
        print(current, currentLen);

        //подбор множителя
        while (l <= r) {
            int m = (l + r) >> 1;
            unsigned int podobrannoyZnachenieLen = 0;
            unsigned short int* podobrannoyZnachenie = multipleByShortBigOsn(b, lenB, m, podobrannoyZnachenieLen);
            print(podobrannoyZnachenie, podobrannoyZnachenieLen);

            if (currentLen >= podobrannoyZnachenieLen && compare(podobrannoyZnachenie, current, podobrannoyZnachenieLen, currentLen) <= 0) {
                x = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        //запись подобранного множителя и вычитание
        result[i] = x;
        unsigned int bufLen = 0;
        unsigned short int* subtracted = multipleByShortBigOsn(b, lenB, x, bufLen);
        current = minusBigOsn(current, subtracted, currentLen);
        print(current, currentLen);

        if (lenA - lenB - 1 - count > lenA) {
            break;
        }

        if (current[currentLen - 1] != 0) {

            unsigned short int*  newCurrent = new unsigned short int[currentLen + 1];
            for (int j = 0; j < currentLen; j++){
                newCurrent[j + 1] = current[j];
            }
            currentLen = currentLen + 1;
            if (lenA - lenB - 1 - count <= lenA) {
                newCurrent[0] = a[lenA - lenB - 1 - count];
            }
            current = newCurrent;

        } else {
            int numOfZero = findZeros(current, currentLen);
            if (numOfZero != currentLen) {
                while(current[currentLen - 1] == 0 ) {
                    for (int j = currentLen - 1; j > 0; j--) {
                        current[j] = current[j - 1];
                    }
                }
            }

            for (int i = 0; i < numOfZero; i++) {
                current[i] = 0;
            }
            print(current, currentLen);
            if (lenB != currentLen && numOfZero > 1 ) {
                currentLen = lenB;
                unsigned short int* newCurrent = new unsigned short int[currentLen];
                for (int j = currentLen - 1; j >= 0; j--) {
                    newCurrent[j] = current[j + 1];
                }

                current = newCurrent;

            }
            if (lenA - lenB - 1 - count <= lenA) {
                current[0] = a[lenA - lenB - 1 - count];
            }

        }

        i--;
        count++;
        print(current, currentLen);
    }

    printLine();
    //сдвиг результата, чтобы получить корректные значения
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < resLen - 1; j++) {
            result[j] = result[j + 1];
        }
        result[resLen - 1 - i] = 0;
    }

    print(result, resLen);
    print(current, currentLen);
    //todo: преобразовать вывод данных результата - есть ошибка в порядке
    return result;
}

unsigned short int* schoolDivision_quotient_and_remainder(unsigned short int *a, unsigned int lenA,
                                                          unsigned short int *b, unsigned int lenB, unsigned int &resLen) {
    //случай, если делитель больше делимго
    if (lenA < lenB) {
        resLen = 1;
        return new unsigned short int{0};
    }

    //случай, если числа одинаковой длины
    if (lenA == lenB) {
        int comparison = compare(a, b, lenA);
        //случай, когда делитель больше делимого
        if (comparison < 0) {
            resLen = 1;
            return new unsigned short int{0};
        }

        //случай, когда делитель равен делимому
        if (comparison == 0) {
            resLen = 1;
            return new unsigned short int{1};
        }
    }

    resLen = lenA;
    unsigned short int* result = new unsigned short int[lenA];
    for (int i = 0; i < resLen; i++) {
        result[i] = 0;
    }

    unsigned short int* current = new unsigned short int[lenB];
    for (int i = 0; i < lenB; i++) {
        current[lenB - i - 1] = a[lenA - i - 1];
    }

    unsigned int currentLen = lenB;
    int count = 0;

    int i = lenA - 1;

    while (compare(current, b, currentLen, lenB) >= 0
           || lenA - lenB - 1 - count <= lenA) {
        printLine();

        unsigned short int x = 0;
        unsigned short int l = 0, r = BIG_OSN;

        print(result, resLen);
        print(current, currentLen);

        //подбор множителя
        while (l <= r) {
            int m = (l + r) >> 1;
            unsigned int podobrannoyZnachenieLen = 0;
            unsigned short int* podobrannoyZnachenie = multipleByShortBigOsn(b, lenB, m, podobrannoyZnachenieLen);
            print(podobrannoyZnachenie, podobrannoyZnachenieLen);

            if (currentLen >= podobrannoyZnachenieLen && compare(podobrannoyZnachenie, current, podobrannoyZnachenieLen, currentLen) <= 0) {
                x = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        //запись подобранного множителя и вычитание
        result[i] = x;
        unsigned int bufLen = 0;
        unsigned short int* subtracted = multipleByShortBigOsn(b, lenB, x, bufLen);
        current = minusBigOsn(current, subtracted, currentLen);
        print(current, currentLen);

        if (lenA - lenB - 1 - count > lenA) {
            break;
        }

        if (current[currentLen - 1] != 0) {

            unsigned short int*  newCurrent = new unsigned short int[currentLen + 1];
            for (int j = 0; j < currentLen; j++){
                newCurrent[j + 1] = current[j];
            }
            currentLen = currentLen + 1;
            if (lenA - lenB - 1 - count <= lenA) {
                newCurrent[0] = a[lenA - lenB - 1 - count];
            }
            current = newCurrent;

        } else {
            int numOfZero = findZeros(current, currentLen);
            if (numOfZero != currentLen) {
                while(current[currentLen - 1] == 0 ) {
                    for (int j = currentLen - 1; j > 0; j--) {
                        current[j] = current[j - 1];
                    }
                }
            }

            for (int i = 0; i < numOfZero; i++) {
                current[i] = 0;
            }
            print(current, currentLen);
            if (lenB != currentLen && numOfZero > 1 ) {
                currentLen = lenB;
                unsigned short int* newCurrent = new unsigned short int[currentLen];
                for (int j = currentLen - 1; j >= 0; j--) {
                    newCurrent[j] = current[j + 1];
                }

                current = newCurrent;

            }
            if (lenA - lenB - 1 - count <= lenA) {
                current[0] = a[lenA - lenB - 1 - count];
            }

        }

        i--;
        count++;
        print(current, currentLen);
    }

    printLine();
    //сдвиг результата, чтобы получить корректные значения
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < resLen - 1; j++) {
            result[j] = result[j + 1];
        }
        result[resLen - 1 - i] = 0;
    }

    print(result, resLen);
    print(current, currentLen);
    unsigned short int* q_and_r = new unsigned short int[resLen + currentLen];
    for (int i = 0; i < resLen; i++) {
        q_and_r[i] = result[i];
    }

    for (int i = 0; i < currentLen; i++) {
        q_and_r[resLen + i] = current[i];
    }
    resLen = resLen + currentLen;
    //todo: преобразовать вывод данных результата - есть ошибка в порядке
    return q_and_r;
}

unsigned short int* schoolDivisionLongByShort_quotient(unsigned short int *a, unsigned int lenA,
                                                       unsigned short int b, unsigned int &resLen) {

    resLen = lenA;
    unsigned short int* result = new unsigned short int[resLen];
    unsigned short int ost = 0;

    for (int i = lenA - 1; i >= 0; i--) {
        unsigned int cur = ost * BIG_OSN + a[i];
        result[i] = cur / b;
        ost = cur % b;
    }

    std::cout << " Ostatok: " << ost << std::endl;

    return result;
}