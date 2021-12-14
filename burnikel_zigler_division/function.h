//
// Created by mmaslov on 09.12.2021.
//

#ifndef UNTITLED_FUNCTION_H
#define UNTITLED_FUNCTION_H

//a - 2 words
//b - 1 word
unsigned short int* divTwoDigitsByOne(unsigned int a[], unsigned int b[]);

unsigned short int* divThreeHalvesByTwo(unsigned short int a1,
                         unsigned short int a2,
                         unsigned short int a3,
                         unsigned short int b1,
                         unsigned short int b2);


unsigned short int* divThreeLongHalvesByTwo(unsigned short int* a1,
                                            unsigned short int* a2,
                                            unsigned short int* a3,
                                            unsigned short int* b1,
                                            unsigned short int* b2,
                                            unsigned int len);

unsigned short int* recursiveDivision(unsigned short int* a,
                                      unsigned short int* b,
                                      unsigned int n);

#endif //UNTITLED_FUNCTION_H
