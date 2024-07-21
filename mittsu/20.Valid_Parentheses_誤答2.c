//"()[]{}"の場合考慮できてない。


bool isValid(char* s) {
    bool result = true;
    int s_len = strlen(s);

    for(int i = 0; i < s_len/2; i++){
        switch(s[i*2]){
            case '(':
                if(s[s_len-i*2-1] != ')'){
                    result = false;
                }
                break;

            case '{':
                if(s[s_len-i*2-1] != '}'){
                    result = false;
                }
                break;            

            case '[':
                if(s[s_len-i*2-1] != ']'){
                    result = false;
                }            

            default:
                break;
        }

    }

    return result;
}