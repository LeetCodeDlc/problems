/*
0ms
7.89MB

*/

#include <string.h> 

int lengthOfLastWord(char* s) {
    int s_len = strlen(s);
    int lengthOfLastWord = 0;
    int i = s_len -1;

    //後ろから探索し、スペースならスキップ
    while(s[i] >= 0 && s[i]==' '){
        i--;
    }

    //スペースじゃないものが続く限り数える
    //単語が1しかない場合(先頭の場合)も考慮
    while(i>=0 && s[i]!=' '){
        lengthOfLastWord++;
        i--;
    }

    return lengthOfLastWord;
}