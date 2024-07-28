/*
0ms
7.82MB

*/
int strStr(char* haystack, char* needle) {
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);
    bool occur = false;

    for(int i = 0; i < haystack_len; i++){
        if(haystack[i] == needle[0]){
            occur = true;
            for(int j = 0; j < needle_len; j++){
                if(haystack[i +j] != needle[j]){
                    occur = false;
                    break;
                }
            }

            //存在したら最初の要素番号を返す
            if(occur == true){
                return i;
            }
            
        }
    }
    return -1;
}