//
// Created by max on 16.12.2021.
//

#include "../../headers/burnikel_zigler.h"
#include "../../headers/burnikel_zigler_big_osn.h"
#include "../../headers/util_function.h"
#include "../headers/burnikel_zigler_test.h"


void test1_osn() {
    unsigned short int a[] = {9, 9, 9, 9,
                              9, 9, 9, 9,
                              9, 9, 9, 9,
                              9, 9, 9, 9};

    unsigned short int b[] = {5, 5, 5, 5,
                              5, 5, 5, 5};
    unsigned short int n = 8;

    unsigned short* result = recursiveDivision(a, b, n);
    printLine();
    print(result, n);
}

void test1_big_osn() {
    unsigned short int a[] = {9, 9, 9, 9,
                              9, 9, 9, 9,
                              9, 9, 9, 9,
                              9, 9, 9, 9};

    unsigned short int b[] = {5, 5, 5, 5,
                              5, 5, 5, 5};
    unsigned short int n = 8;

    unsigned short* result = recursiveDivision_BigOsn(a, b, n);
    printLine();
    print(result, n);
}

