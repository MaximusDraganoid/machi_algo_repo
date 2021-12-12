//
// Created by mmaslov on 10.12.2021.
//

#include "function.h"

//todo: проверить верность работы операций со сдвигами!!! возможно есть ошибка в текущей работе с ними
//todo: скорее всего для получения младших 16 бт нужно просто присвоить значение к short int, а при
//todo: получении старших уже выполнять побитовые сдвиги

//a - 2 words
//b - 1 word
unsigned * divTwoDigitsByOne(unsigned int a[], unsigned int b[]) {
    unsigned int AH = a[1], AL = a[0];
    unsigned short int a1 = AH >> 16, a2 = AH <<16;
    unsigned short int a3 = AL >> 16, a4 = AL <<16;
    unsigned short int b1 = b[0] >> 16, b2 = b[0] << 16;

    unsigned short int q1, q2, r1, r2, s1, s2;

    unsigned short int *firstResult = divThreeHalvesByTwo(a1, a2, a3, b1, b2);

    r1 = firstResult[1];
    r2 = firstResult[0];
    q1 = firstResult[2];

    unsigned short int *secondResult = divThreeHalvesByTwo(r1, r2, a4, b1, b2);

    s1 = secondResult[1];
    s2 = secondResult[0];
    q2 = secondResult[2];

    unsigned int *result = new unsigned int[2];
    unsigned int result1 = q1 << 16;
    unsigned int result2 = q2 >> 16;
    result[0] = result1 + result2;

    result1 = s1 << 16;
    result2 = s2 >> 16;
    result[1] = result1 + result2;

    return result;
}

unsigned short* divThreeHalvesByTwo(unsigned short int a1,
                                    unsigned short int a2,
                                    unsigned short int a3,
                                    unsigned short int b1,
                                    unsigned short int b2) {

    return nullptr;
}
