#ifndef MYSTRINGS_H
#define MYSTRINGS_H

#include <iostream>

//This is a header file for the string library things so I don't have to copy and paste stuff.
//This project is also a headache too -_-
size_t myStringLength(const char*str);

int myStringCompare(const char*str1, const char*str2);

char *myStringCopy(char* destination, const char* source);

char *myStringCat(char*destination, const char* source);

#endif