#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    int values[] =  {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    // store last string
    char* result = malloc(100);

    // end of string
    result[0] = '\0';
    for (int i = 0; i <13 ; i++) {
        while (num >= values[i]) {

            // only the numbers of values can be added to a roman numeral, and only one of those symbols ever get added
            strcat(result, symbols[i]);

            // added the corresponding letter represenation;
            num -= values[i];
        }
    }
    return result;

}