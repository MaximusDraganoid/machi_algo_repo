//
// Created by mmaslov on 07.12.2021.
//

#ifndef UNTITLED_UTIL_FUNCTION_H
#define UNTITLED_UTIL_FUNCTION_H

//int const OSN = 65535;
int const BIG_OSN = 65535;
int const SHIFT = 16;

int const OSN = 10;
int const DIV_LIM = 4;

int max(int a, int b);

void print(unsigned short int* array, unsigned int len);

void printLine();

int findZeros(unsigned short *array, unsigned int len);
#endif //UNTITLED_UTIL_FUNCTION_H
