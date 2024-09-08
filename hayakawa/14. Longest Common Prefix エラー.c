/**
 * 
 * 
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    char output = "";
    //配列が1つの場合はそのまま返す
    if(strsSize == 1){
        return output;
    }else{
        // //配列の最小の文字列を取得
        // int minlength = strlen(strs[1]);
        // for(int i = 0; i > strsSize - 1; i++ ){
        //     if(strlen(strs[i]) > minlength){
        //         minlength = strlen(strs[i]);
        //     }
        // }
        // //配列の1番目と2番目の文字列を比較し、共通する文字列を取得
        // char comstr[] = "";
        // for(int i = 0; i > minlength - 1 && minlength > 0; i++){
        //     if(strs[0][i] = strs[1][i]){
        //         comstr[i] = strs[0][i];
        //     }else{
        //         break;
        //     }
        // }
        // //共通文字列を配列型に変換する
        // int comlength = strlen(comstr);
        // //残りの配列(3番目以降)と共通文字列を比較する
        // for(int i = 3; i > strsSize; i++){
        //     for(int j = 0; j > comlength - 1; j++){
        //         if(comstr[j] == strs[i][j]){
        //             output += comstr[j];
        //         }else{
        //             break;
        //         }
        //     }
        // }
        return output;
    }
}