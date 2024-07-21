/*
3ms 
メモリ8.66MB
せっかくなのでスタックの概念を使用してみた

*/

#define MAX_SIZE 10000

//スタックの構造体定義
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

//初期化
void initializeStack(Stack* stack){
    stack->top = -1;
}

//スタックに文字をプッシュ
void push(Stack* stack, char bracket){
    stack->data[++(stack->top)] = bracket;
}

//最後尾を取り出す
char pop(Stack* stack){
    // スタックが空でないことを確認
    if (stack->top >= 0) { 
        return stack->data[(stack->top)--];
    } else {
        //スタックが空のときはエラー値としてnull文字を返す
        printf("Stack underflow\n");
        return '\0'; 
    }
}


bool isValid(char* s) {
    int s_len = strlen(s);
    //スタックを定義
    Stack newStack;
    //初期化
    initializeStack(&newStack);

    for(int i = 0; i < s_len; i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            //始まりのカッコならスタックにプッシュ
            push(&newStack, s[i]);
        }else if(s[i]=='}' || s[i]==')' || s[i]==']'){
            //閉じカッコならスタックからポップしたものと組み合わせが一致するか確認
            char correspondChar = pop(&newStack);
            switch (correspondChar){
                case '\0':
                    return false;
                    break;
                    
                case '{':
                    if(s[i] != '}'){
                        return false;
                    }
                    break;

                case '(':
                    if(s[i] != ')'){
                        return false;
                    }
                    break;  

                case '[':
                    if(s[i] != ']'){
                        return false;
                    }
                    break;   

                default:
                    break;                                
            }

        }else{
            return false;
        }
    }

    //ループ後スタックの要素が0であればtrueを返す
    if(newStack.top == -1){
        return true;
    }else{
        return false;
    }

}