/*
誤答
121や10などの正の数は考慮されているが
-121等の負の数を考慮できていない

*/

bool isPalindrome(int x) {
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

    //配列の中の対応する数字を比較して一致しなければfalseを戻す
    for(int i = 0; i < digit/2; i++){
        if(places[i] != places[digit - i -1]){
            return false;
        }
    }
    
    //すべて一致していればtrueを戻す
    return true;

}
