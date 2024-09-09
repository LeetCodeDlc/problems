/**
 * 4ms
 * 8.04MB
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    //配列が1つの場合はそのまま返す
    if(strsSize == 1){
        return strs[0];
    }else{
        //配列の最小の文字列を取得
        int minlength = strlen(strs[0]);
        for(int i = 0; i < strsSize ; i++ ){
            if(strlen(strs[i]) < minlength){
                minlength = strlen(strs[i]);
            }
        }
        //配列の1番目と2番目の文字列を比較し、共通する文字列を取得
        char *comstr = (char*)malloc(minlength + 1);
        int i;
        for(i = 0; i < minlength; i++){
            if(strs[0][i] == strs[1][i]){
                comstr[i] = strs[0][i];
            }else{
                break;
            }
        }
        comstr[i] = '\0';
        //共通文字列を配列型に変換する
        int comlength = strlen(comstr);
        //残りの配列(3番目以降)と共通文字列を比較する
        for(int i = 2; i < strsSize; i++){
            for(int j = 0; j < comlength; j++){
                if(comstr[j] != strs[i][j]){
                    comstr[j] = '\0';
                    comlength = j;
                    break;
                }
            }
        }
        return comstr;
    }
}