
// Submitは通っていない。

char* addBinary(char* a, char* b) {

    int lengthA = strlen(a);
    int lengthB = strlen(b);
    // それぞれの長さを取得
    int minLength = (lengthA > lengthB) ? lengthB : lengthA;
    int maxLength = (lengthA > lengthB) ? lengthA : lengthB;
    char* longerChar = (lengthA > lengthB) ? a : b;

    int diffLength = maxLength - minLength;

    // 戻り値の箱を作成
    char* output = (char*)malloc((maxLength + 2) * sizeof(char));
    memset(output, '0', maxLength + 1); // 配列を '0' で初期化
    output[maxLength + 1] = '\0';       // 終端文字を追加

    // ポイントセット
    char* endA = a + lengthA - 1;
    char* endB = b + lengthB - 1;
    char* outputEnd = output + maxLength;

    // 追加if(endAとendBがある時)
    printf("minLength : %d\n", minLength);
    for (int i = 0; i < minLength; i++) {
        // int sumEnd = *endA + *endB;
        printf("endA : %c\n", *endA);
        printf("endB : %c\n", *endB);
        printf("minLength : %d\n", minLength);
        printf("output : %c\n", *outputEnd);
        if (*endA == '1' && *endB == '1') {
            if (*outputEnd == '0') {
                *outputEnd = '0';
                outputEnd--;
                *outputEnd = '1';
            } else {
                *outputEnd = '1';
                outputEnd--;
                *outputEnd = '1';
            }
        } else if (*endA == '0' && *endB == '0') {
            if (*outputEnd == '0') {
                *outputEnd = '0';
                outputEnd--;
            } else {
                *outputEnd = '1';
                outputEnd--;
            }
        } else {
            if (*outputEnd == '0') {
                *outputEnd = '1';
                outputEnd--;
            } else {
                *outputEnd = '0';
                outputEnd--;
                *outputEnd = '1';
            }
        }
        endA--;
        endB--;
    }
    for (int i = 0; i < diffLength; i++) {
        if (*outputEnd == '1') {
            if (*longerChar == '1') {
                *outputEnd = '0';
                outputEnd--;
                *outputEnd = '1';
            } else {
                *outputEnd = '1';
                outputEnd--;
            }
        } else {
            *outputEnd = *longerChar;
            outputEnd--;
            longerChar--;
        }
    }
    // 先頭の余分な '0' を取り除く
    char* result = output;
    while (*result == '0' && *(result + 1) != '\0') {
        result++;
    }
    return result;
}

// 作り直し
char* addBinary(char* a, char* b) {
    //初期値設定
    int lengthA = strlen(a);
    int lengthB = strlen(b);
    // 最大値と最小値を取得
    int minLength = (lengthA > lengthB) ? lengthB : lengthA;
    int maxLength = (lengthA > lengthB) ? lengthA : lengthB;
    char* longerChar = (lengthA > lengthB) ? a : b;

    // int型に変換
    int* intA = (int*)malloc((maxLength + 2) * sizeof(int));
    intA = atoi(a);
    printf("intA: %d\n", intA);
    // resultの定義
    char* result = (char*)malloc((maxLength + 2) * sizeof(char));
    memset(result, '0', maxLength + 1); // 配列を '0' で初期化
    result[maxLength + 1] = '\0';       // 終端文字を追加

    // 末尾から比較していく
    // ポイントセット
    char* endA = a + lengthA - 1;
    char* endB = b + lengthB - 1;
    char* resultEnd = result + maxLength;

    //桁上がり処理用の変数定義
    bool carryFlg = false;

    while(endA != NULL && endB != NULL){
        int sum = endA* + endB*
        if (carryFlg == true){
            sum += 1;
            carryFlg = false;
        }
        if (sum >= 2){
            carryFlg = true;
            sum -= 2;
        }
        *resultEnd = sum;
        resultEnd--;
        endA--;
        endB--;
    }
    //【TODO】endAとendBに対応できるようにする必要がある。
    while(longerChar != NULL){
        int temp = *longerChar;
        if (carryFlg == true){
            temp += 1;
            carryFlg = false;
        }
        if (temp >= 2){
            carryFlg = true;
            temp -= 2;
        }
        *resultEnd = temp;
        resultEnd--;
        longerChar--;
    }

    // if(sum>=2){sum=0}
    
}