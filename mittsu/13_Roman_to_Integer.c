/*
3ms
メモリ5.78MB
*/

#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {

    // 文字の長さを取得
    int s_len = strlen(s);

    char SYMBOLS[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int SYMBOLS_VALUE[] = {1, 5, 10, 50, 100, 500,1000};

    //1のくらいから順に処理するために探索する位を保持する
    int place_int = 0;
    char place = SYMBOLS[place_int];
    int sum = 0;
    
    //減算処理が発生する場合をフラグで管理
    int minus_flg = 0;

    // 後ろの文字から処理する
    for(int i = 0; i < s_len; i++){
        //処理中の文字が探索文字に一致する場合、合計に加算する
        if(s[s_len - i - 1] == place){

            sum = sum + SYMBOLS_VALUE[place_int];
        
        //一致しなくなったとき
        }else{
            
            //まずは探索している位が以下の場合で、かつそれぞれ今の数字が特定のケースに該当する場合、減算する(IXなどの処理)
            switch(place){
                case 'V':
                case 'X':
                    if(s[s_len - i - 1]=='I'){
                        sum = sum -1;
                        minus_flg = 1;
                    }
                    break;

                case 'L':
                case 'C':
                    if(s[s_len - i - 1]=='X'){
                        sum = sum -10;
                        minus_flg = 1;
                    }
                    break;

                case 'D':
                case 'M':
                    if(s[s_len - i - 1]=='C'){
                        sum = sum -100;
                        minus_flg = 1;
                    }
                    break;

                default:

                    break;
            }

            //一致しないときで減産しないときは一致するまで探索の位を上げて加算(単純な位上げの処理)
            if(minus_flg==0){
                while(s[s_len - i - 1] != place){
                    place_int++;
                    place =SYMBOLS[place_int];
                }
                sum += SYMBOLS_VALUE[place_int];
            }

            minus_flg = 0;

        }

    }

    return sum;

}


int main(){
    int i = romanToInt("MCMXCIV");
    printf("%d", i);
}