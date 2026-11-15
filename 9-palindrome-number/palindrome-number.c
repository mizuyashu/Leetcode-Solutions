bool isPalindrome(int x) {
    if (x<0){
        return false;
    }
    double reversed = 0.0;
    double remainder = 0.0;
    int original = x;
    while (x!=0){
        remainder = x %10;
        reversed = reversed * 10 + remainder;
        x = x/10;

    }
    if (reversed == original) {
        return true;
    } 
    else {
        return false;
    }

}
