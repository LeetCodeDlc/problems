/* 
0 ms
7.84 MB
 */
int lengthOfLastWord(char* s) {
    //返り値の変数宣言
    int length = strlen(s);
    int output = 0;
    bool blankFlg = false;

    //文字の繰り返し
    for (int i = 0; i < length; i++) {
        //新しい文字列が始まっていたらリセット
        if(s[i] != ' ' && blankFlg == true){
            output = 0;
        }
        //文字列である場合はカウント
        if(s[i] != ' '){
            output++;
            blankFlg = false;
        }
        //ブランクだった場合フラグセット
        else if(s[i] == ' '){
            blankFlg = true;
        }
    }
    return output;
}

//サンプルコード
int lengthOfLastWord(char* s) {
    int res=0;
    //全体の数-1
    int i=strlen(s)-1;

    //iが0より大きい ブランクだった場合
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    //iが0より大きい ブランクでない場合
    while(i >=0 && s[i] != ' '){
        res++;
        i--;
    }
    return res;
}