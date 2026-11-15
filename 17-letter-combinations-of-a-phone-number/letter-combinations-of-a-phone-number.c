/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

char** letterCombinations(char* digits, int* returnSize) {
    
    char* map[] = {"", "", "abc", "def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n = strlen(digits);

    int total = 1;

    // total char of the output (3 or 4 * number of digits since each is mapped to that many letters)
    for (int i  = 0; i < n; i++){

        total = total * strlen(map[digits[i] - 48]);
    }

    char** results = malloc(total * sizeof(char*));

    for (int k = 0; k < total; k++){
        results[k] = malloc(n+1);
        int temp = k;
        for (int p = n-1; p>=0; p--) {
            char* letters = map[digits[p] -48];
            int len = strlen(letters);
            results[k][p] = letters[temp % len];
            temp = temp / len;
        }
        results[k][n] = '\0';
    }
    *returnSize = total;
    return results;
}