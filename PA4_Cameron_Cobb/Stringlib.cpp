#include "Stringlib.h"
#include <iostream>


size_t myStringLength(const char* str){ //why would this function be needed????
    int length = 0;
    for(; str[length] != '\0'; length++) continue;

    length = length * sizeof(char);
    return length;

}

int myStringCompare(const char*str1, const char*str2){ //why would this function be needed for this project also?
    for (int i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++){
		int val1 = str1[i], val2 = str2[i];
		(val1 >= 97)? val1 -= 32 : val1 -= 0;
		(val2 >= 97)? val2 -= 32 : val1 -= 0;
		if (val1 > val2){
			return 1;
		}else if (val1 < val2){
			return -1;
		}
	}
    return 0;
}

char *myStringCopy(char* destination, const char* source){ //why would I use this function also???!!!
    char *start = destination;

    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; // add '\0' at the end
    return start;
}

char *myStringCat(char*destination, const char* source){ //This was taken from past CS135 project
    char *start = destination;

    while(*destination != '\0'){
        destination++;
    }

    while(*source != '\0'){
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
    return start; 
}
