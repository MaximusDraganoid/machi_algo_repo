//
// Created by mmaslov on 10.12.2021.
//

#include "../headers/burnikel_zigler.h"
#include "../headers/math_func.h"
#include "../headers/util_function.h"


//todo: проверить верность работы операций со сдвигами!!! возможно есть ошибка в текущей работе с ними
//todo: скорее всего для получения младших 16 бт нужно просто присвоить значение к short int, а при
//todo: получении старших уже выполнять побитовые сдвиги

//a - 2 words
//b - 1 word
unsigned short int* divTwoDigitsByOne(unsigned short int a[], unsigned short int b[]) {
    unsigned short int a1 = a[3], a2 = a[2], a3 = a[1], a4 = a[0],
                        b1 = b[1], b2 = b[0];

    unsigned short int q1, q2, r1, r2, s1, s2;

    unsigned short int *firstResult = divThreeHalvesByTwo(a1, a2, a3, b1, b2);

    r1 = firstResult[1];
    r2 = firstResult[0];
    q1 = firstResult[2];

    unsigned short int *secondResult = divThreeHalvesByTwo(r1, r2, a4, b1, b2);

    s1 = secondResult[1];
    s2 = secondResult[0];
    q2 = secondResult[2];

    unsigned short int *result = new unsigned short int[2];
    result[0] = q2;
    result[1] = q1;

    result[2] = s2;
    result[3] = s1;

    return result;
}

unsigned short* divThreeHalvesByTwo(unsigned short int a1,
                                    unsigned short int a2,
                                    unsigned short int a3,
                                    unsigned short int b1,
                                    unsigned short int b2) {
    unsigned short int a[] = {a2, a1};
    unsigned int resLen = 0;
    unsigned short int q = schoolDivisionLongByShort_quotient(a, 2, b1, resLen)[0];
    unsigned short int resLen1 = 0;
    unsigned short int* q_by_b1 = multiply(new unsigned short int{q}, new unsigned short int{b1}, 1, resLen1);

    unsigned short int* c = minus(a, q_by_b1, 2);

    unsigned short int* d = multiply(new unsigned short int{q}, new unsigned short int{b2}, 1, resLen1);

    unsigned short int reducing[]{a3, c[0]};
    if (compare(reducing, d, 2) < 0) {
        q--;
        unsigned int newLast = reducing[0] + OSN;
        reducing[0] = newLast % OSN;
        reducing[1] += newLast / OSN;

        if (compare(reducing, d, 2) < 0) {
            q--;
            newLast = reducing[0] + OSN;
            reducing[0] = newLast % OSN;
            reducing[1] += newLast / OSN;
        }
    }
    unsigned short int* remainder = minus(reducing, d, 2);
    unsigned short int* result = new unsigned short int[3];
    result[2] = q;
    result[0] = remainder[0];
    result[1] = remainder[1];

    return result;
}

//num of len 2*n division by nom of len n
unsigned short int* recursiveDivision(unsigned short int* a,
                                      unsigned short int* b,
                                      unsigned int n) {
    if (n % 2 == 1 || n <= DIV_LIM) {
        unsigned int resultLen = 0;
        //долже возвращать склейку из целого и остатка
        return schoolDivision_quotient_and_remainder(a, 2 * n, b, n, resultLen);
        //школьное деление A на B
    } else {
        unsigned short int* a4 = a;
        unsigned short int* a3 = a + n / 2;
        unsigned short int* a2 = a + n;
        unsigned short int* a1 = a + 3 * n / 2;

        unsigned short int* b2 = b;
        unsigned short int* b1 = b + n/2;

        unsigned short int* q1_and_r = divThreeLongHalvesByTwo(a1, a2, a3, b1, b2, n/2);

        unsigned short int* r2 = q1_and_r + n/2;
        unsigned short int* r1 = q1_and_r + n;

        unsigned short int* q2_and_s = divThreeLongHalvesByTwo(r1, r2, a3, b1, b2, n/2);

        unsigned short int* result = new unsigned short int[2 * n];
        for (int i = 0; i < n/2; i++) {
            result[i] = q1_and_r[i];
        }

        for (int i = 0; i < 3 * n / 2; i++) {
            result[i + n/2] = q2_and_s[i];
        }

        return result;
    }
}

unsigned short int* divThreeLongHalvesByTwo(unsigned short int* a1,
                                            unsigned short int* a2,
                                            unsigned short int* a3,
                                            unsigned short int* b1,
                                            unsigned short int* b2,
                                            unsigned int len) {
    unsigned short int* a1_a2 = new unsigned short int[2 * len];
    for (int i = 0; i < len; i++) {
        a1_a2[i] = a2[i];
    }
    for (int i = 0; i < len; i++) {
        a1_a2[i + len] = a1[i];
    }

    unsigned short int* q = recursiveDivision(a1_a2, b1, len);
    unsigned short int resultLenOfMultiplication = 0;
    unsigned short int* q_by_b1 = multiply(q, b1, (unsigned short int)len, resultLenOfMultiplication);

    unsigned short int* c = minus(a1_a2, q_by_b1, 2 * len);

    unsigned short int* d = multiply(q, b2, (unsigned short int)len, resultLenOfMultiplication);

    for(int i = 0; i < len; i++) {
        c[i + len] = c[i];
    }

    for (int i = 0; i < 0; i++) {
        c[i] = a3[i];
    }

    unsigned short int* remainder;
    if (compare(c, d, 2 * len) < 0) {
        //уменьшение на единицу делителя
        unsigned short int zaem = 1;
        int count = 0;
        while (zaem != 0) {
            unsigned short int vichitaniye = q[count] - 1;
            if (vichitaniye > q[count]) {
                zaem = 1;
            } else {
                zaem = 0;
            }
            count++;
        }
        unsigned int perenos = 0;
        count = 0;
        unsigned int buf = 0;
        do {
            if (perenos == 0) {
                buf += OSN;
            }
            buf = c[count] + perenos;
            c[count] = buf % OSN;
            perenos = buf / OSN;

        } while (perenos != 0);

        if (compare(c, d, 2 * len) < 0) {
            //уменьшение на единицу делителя
            zaem = 1;
            count = 0;
            while (zaem != 0) {
                unsigned short int vichitaniye = q[count] - 1;
                if (vichitaniye > q[count]) {
                    zaem = 1;
                } else {
                    zaem = 0;
                }
                count++;
            }
            perenos = 0;
            count = 0;
            buf = 0;
            do {
                if (perenos == 0) {
                    buf += OSN;
                }
                buf = c[count] + perenos;
                c[count] = buf % OSN;
                perenos = buf / OSN;

            } while (perenos != 0);
        }

    }
    remainder = minus(c, d, 2 * len);

    unsigned short int* result = new unsigned short int[3 * len];
    for (int i = 0; i < len; i++) {
        result[i] = q[i];
    }
    for (int i = 0; i < 2 * len; i++) {
        result[i + len] = remainder[i];
    }

    return result;
}