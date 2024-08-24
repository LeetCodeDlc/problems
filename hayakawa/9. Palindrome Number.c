bool isPalindrome(int x) {
    char y[50];
    int  length;
    int i = 0;
    int j;
    sprintf(y, "%d", x);
    length = strlen(y);
    j = length - 1;

    while(i <= j){
        if(y[i] != y[j]){
            return false;
        }
        i = i + 1;
        j = j - 1;
    }
    return true;
}