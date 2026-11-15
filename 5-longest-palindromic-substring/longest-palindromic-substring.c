#include <stdio.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    int start = 0, best = 0;

    for (int i = 0; i < n; i++) {
        
        // center for odd
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        int odd = r -l -1;


        // center for even
        l = i; 
        r = i+1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        int even = r - l -1;

        int len = -1;

        // check which palendromes are bigger
        if (odd > even) {
            len = odd;
        } else {
            len = even;
        }

        // sets length of largest palendrome and the start
        if (len > best) {
            best = len;
            
            // removes middle and -avg length
            start = i - (len - 1) / 2;
        }
    }

    // new string + \0
    char* result = malloc(best + 1);

    for (int k = 0; k < best; k++) {
        result[k] = s[start + k];
    }
    result[best] = '\0';
    return result;

    


}