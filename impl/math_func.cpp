//
// Created by mmaslov on 07.12.2021.
//
#include "math_func.h"
#include "util_function.h"
#include <iostream>

int findZeros(unsigned short *array, unsigned int len);

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
            return 1;
        } else {
            return -1;
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

//умножение длинных чисел разной длины
unsigned short int *multiplyDiffLen(unsigned short int firstArray[],
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


//умножение длинных чисел одинаковой длины
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

    while (compare(current, b, currentLen, lenB) >= 0
        || lenA - lenB - 1 - count <= lenA) {
        printLine();

        unsigned short int x = 0;
        unsigned short int l = 0, r = OSN;

        print(result, resLen);
        print(current, currentLen);

        //подбор множителя
        while (l <= r) {
            int m = (l + r) >> 1;
            unsigned int podobrannoyZnachenieLen = 0;
            unsigned short int* podobrannoyZnachenie = multipleByShort(b, lenB, m, podobrannoyZnachenieLen);
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
        unsigned short int* subtracted = multipleByShort(b, lenB, x, bufLen);
        current = minus(current, subtracted, currentLen);
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
    print(result, resLen);
    print(current, currentLen);
    //todo: преобразовать вывод данных результата - есть ошибка в порядке
    return result;
}

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

unsigned short int* schoolDivision_remainder(unsigned short int *a, unsigned int lenA,
                                            unsigned short int *b, unsigned int lenB) {

}

unsigned short int* schoolDivisionLongByShort_quotient(unsigned short int *a, unsigned int lenA,
                                                       unsigned short int b, unsigned int &resLen) {

    resLen = lenA;
    unsigned short int* result = new unsigned short int[resLen];
    unsigned short int ost = 0;

    for (int i = lenA - 1; i >= 0; i--) {
        unsigned int cur = ost * OSN + a[i];
        result[i] = cur / b;
        ost = cur % b;
    }

    std::cout << " Ostatok: " << ost << std::endl;


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
        unsigned short int l = 0, r = OSN;

        print(result, resLen);
        print(current, currentLen);

        //подбор множителя
        while (l <= r) {
            int m = (l + r) >> 1;
            unsigned int podobrannoyZnachenieLen = 0;
            unsigned short int* podobrannoyZnachenie = multipleByShort(b, lenB, m, podobrannoyZnachenieLen);
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
        unsigned short int* subtracted = multipleByShort(b, lenB, x, bufLen);
        current = minus(current, subtracted, currentLen);
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
