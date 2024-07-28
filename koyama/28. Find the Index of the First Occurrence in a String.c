/* 
0 ms
8.04 MB
 */

int strStr(char* haystack, char* needle) {
    int length1 = strlen(haystack);
    int length2 = strlen(needle);

    for(int i = 0; i < length1; i++){
        //最初の文字が合わない場合
        if(haystack[i] != needle[0]){
            continue;
        }
        //文字を見ていく
        for(int j = 0; j < length2; j++){
            if(haystack[i+j] != needle[j]){
                break;
            }
            if(j == length2 - 1){
                return i;
            }
        }
    }
    return -1;
}