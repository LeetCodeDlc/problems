/*
11MS
一応正解ではあるがもっといいやり方がありそう。
負の数の場合を別で切り分けて考えているのがややひっかかる。
テスト
*/

bool isPalindrome(int x) {
    //負の数ならfalseを返す
    if(x < 0){
        return false;
    }

    //正の数の場合の処理

    int digit = 0;
    int tmp_x = x;

    //xの桁数を求める
    while(tmp_x != 0){
        tmp_x = tmp_x/10;
        digit++;
    }

    //配列(int型×桁数)に必要なメモリを動的に確保
    int *places = (int*)malloc(digit * sizeof(int));

    //10で割っていき配列digitsに格納する
    for(int i = 0; i < digit; i++){
        places[i] = x % 10;
        x = x/10;
    }

    //配列の中の対応する数字を比較して一致しなければfalseを返す
    for(int i = 0; i < digit/2; i++){
        if(places[i] != places[digit - i -1]){
            //動的に割り当てたメモリを開放
            free(places);
            return false;
        }
    }


    
    //すべて一致していればメモリを解放しtrueを返す
    free(places);
    return true;



}
