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


i=0から文字数分ループまわしているけど後半は重複だから余分なんじゃないか
例えば1221って数字が合った時に
x_array[0] とx_reverse[0](=x_array[3)]の比較と
x_array[3] とx_reverse[3](=x_array[0)]の比較を別で実施している気がするけどやっていることが重複している