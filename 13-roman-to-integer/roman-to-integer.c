int romanToInt(char* s) {
    int map [1000] = {0};
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000; 


    int total = 0;
    int prev = 0;

    for (int i = strlen(s)-1; i>=0 ; i--) {
        int current = map[(int)s[i]];

        if (current < prev){
            total = total - current;
        } else{
            total = total + current;
        }
        prev = current;
    }
    return total;
}