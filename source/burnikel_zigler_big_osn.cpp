//
// Created by max on 16.12.2021.
//

#include "../headers/burnikel_zigler_big_osn.h"
#include "../headers/math_func_big_osn.h"
#include "../headers/math_func.h"
#include "../headers/util_function.h"

//num of len 2*n division by nom of len n
unsigned short int* recursiveDivision_BigOsn(unsigned short int* a,
                                      unsigned short int* b,
                                      unsigned int n) {
    if (n % 2 == 1 || n <= DIV_LIM) {
        unsigned int resultLen = 0;
        //долже возвращать склейку из целого и остатка
        unsigned short int* result = schoolDivision_quotient_and_remainder_BigOsn(a, 2 * n, b, n, resultLen);
        print(result, resultLen);
        return result;
        //школьное деление A на B
    } else {
        unsigned short int* a4 = a;
        unsigned short int* a3 = a + n / 2;
        unsigned short int* a2 = a + n;
        unsigned short int* a1 = a + 3 * n / 2;

        unsigned short int* b2 = b;
        unsigned short int* b1 = b + n/2;

        unsigned short int* q1_and_r = divThreeLongHalvesByTwo_BigOsn(a1, a2, a3, b1, b2, n/2);

        unsigned short int* r2 = q1_and_r + n/2;
        unsigned short int* r1 = q1_and_r + n;

        unsigned short int* q2_and_s = divThreeLongHalvesByTwo_BigOsn(r1, r2, a3, b1, b2, n/2);

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

unsigned short int* divThreeLongHalvesByTwo_BigOsn(unsigned short int* a1,
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

    print(a1_a2, len * 2);
    print(b1, len);
    unsigned short int* q = recursiveDivision_BigOsn(a1_a2, b1, len);

    unsigned short int resultLenOfMultiplication = 0;
    unsigned short int* q_by_b1 = multiplyBigOsn(q, b1, (unsigned short int)len, resultLenOfMultiplication);

    unsigned short int* c = minusBigOsn(a1_a2, q_by_b1, 2 * len);

    unsigned short int* d = multiplyBigOsn(q, b2, (unsigned short int)len, resultLenOfMultiplication);

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
    remainder = minusBigOsn(c, d, 2 * len);

    unsigned short int* result = new unsigned short int[3 * len];
    for (int i = 0; i < len; i++) {
        result[i] = q[i];
    }
    for (int i = 0; i < 2 * len; i++) {
        result[i + len] = remainder[i];
    }

    return result;
}