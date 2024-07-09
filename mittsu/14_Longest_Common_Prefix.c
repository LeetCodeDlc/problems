/*
0MS
5.57MB

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {

    int minSize = 200;
    //一番短い要素の文字数を取得
    for(int i = 0; i < strsSize; i++){

        if(strlen(strs[i]) < minSize){

            minSize = strlen(strs[i]);

        }
    }

    char* output = (char*)malloc((minSize + 1) * sizeof(char));

    //文字が一致したらouputに格納
    for(int i = 0; i < minSize; i++){
        for(int j = 1; j < strsSize; j++){
            // 一致しない場合返す
            if(strs[0][i] != strs[j][i]){
                output[i] = '\0'; //終端文字
                return output;
            }
        }
        //全要素で文字が一致したらouputに格納
        output[i] = strs[0][i];
    }
    output[minSize] = '\0'; //終端文字
    return output;

}

int main(){
    char* strs[] = {"abcdef","abcddddww","abcdeeer"};
    int strsSize = 3;
    char* output = longestCommonPrefix(strs, strsSize);


    printf("%s\n", output);
    free(output);
    return 0;
}