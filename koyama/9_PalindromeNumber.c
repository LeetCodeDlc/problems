bool isPalindrome(int x) {

    char str[100];
    int length;
    int x_array[100];
    int x_reverse[100];

    //数値を文字列に変換
    sprintf(str, "%d", x);

    //文字列の長さを取得
    length = strlen(str);

    //配列に格納する
    for (int i = 0; i < length; i++) {
        x_array[i] = str[i] - '0'; // 文字を数値に変換
    }

    //数値を反転させる
    for(int i = length-1, j = 0; i != -1 ; i--, j++){
        x_reverse[j] = x_array[i];
    }

    //配列の中身を比較
     for (int i = 0; i < length; i++) {
        if (x_array[i] != x_reverse[i]) {
            return false;
        }
    }
    return true;
}