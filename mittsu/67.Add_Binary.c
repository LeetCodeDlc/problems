/*
0ms 
7.87MB
*/

char* addBinary(char* a, char* b) {
    int a_strlen = strlen(a);
    int b_strlen = strlen(b);
    int max_len = a_strlen > b_strlen ? a_strlen : b_strlen;
    int carry_up = 0;

    // 繰り上がり+終端文字を考慮し+2
    char* result = (char*)malloc(max_len + 2); 
    
    //終端文字
    result[max_len + 1] = '\0';  


    for(int i = 0; i < max_len; i++) {
        //各位での合計の結果
        int sum = carry_up;


        if(i < a_strlen && a[a_strlen - i - 1] == '1') {
            sum += 1;
        }

        if(i < b_strlen && b[b_strlen - i - 1] == '1') {
            sum += 1;
        }

        //2で割った余りを結果の文字列に格納
        if(sum % 2 == 0){
            result[max_len - i] = '0';
        }else{
            result[max_len - i] = '1';
        }

        //繰り上がり
        carry_up = sum / 2;  
    }

    // 繰り上がりがあれば先頭に '1' を設定
    if(carry_up != 0) {
        result[0] = '1';
        return result;
    }

    //ポインタを1つ進めて(先頭の桁を省いて)返す
    return result + 1;
}