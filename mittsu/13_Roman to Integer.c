int romanToInt(char* s) {

    // 文字の長さを取得
    int s_len = strlen(s);

    char SYMBOLS[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int SYMBOLS_VALUE[] = {1, 5, 10, 50, 100, 500,1000};

    //1のくらいから順に処理するために探索する位を保持する
    int place_int = 0;
    char place = SYMBOLS[place_int];
    int sum = 0;

    // 後ろから処理
    for(int i = 0; i < s_len; i++){
        //現在の文字が探索している位の文字だったら合計に足す
        if(s[s_len - i - 1] == place){

            sum = sum + SYMBOLS_VALUE[place_int];
            
        }else{
            // 探索する文字でなければ以下の処理、位次第で場合分け
            switch(place){
                case 'V':
                case 'X':
                    if(s[s_len - i - 1] == 'I'){
                        sum = sum - 1;
                    }
                    break;

                case 'L':
                case 'C':
                    if(s[s_len - i - 1] == 'X'){
                        sum = sum - 10;
                    }
                    break;

                case 'D':
                case 'M':
                    if(s[s_len - i - 1] == 'C'){
                        sum = sum - 100;
                    }
                    break;

                default:
                    break;

            }

            // 探索している文字に一致していない場合(上記処理完了後)位を上げる
            place_int++;
            place = SYMBOLS[place_int];
          
        }

    }

    return sum;

}

int main(){
    int i = romanToInt("LVIII");
    printf("%d", i);
}