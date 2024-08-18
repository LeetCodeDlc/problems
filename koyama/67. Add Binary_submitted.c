/* 
0 ms
8.19MB
 */
char* addBinary(char* a, char* b) {
    // 初期値設定
    int lengthA = strlen(a);
    int lengthB = strlen(b);
    int maxLength = (lengthA > lengthB) ? lengthA : lengthB;

    // 結果を格納する用
    char* result = (char*)malloc((maxLength + 2) * sizeof(char)); 
    memset(result, '0', maxLength + 1); // 配列を '0' で初期化
    result[maxLength + 1] = '\0';       // 終端文字を追加

    // ポインタを末尾にセット
    char* resultEnd = result + maxLength;

    // 桁上がり処理用の判別フラグ
    bool carry = false;
    
    // 繰り返し回数用変数 ←初期値設定と同じく宣言できた。
    int i = lengthA - 1;
    int j = lengthB - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        // 整数値に変換
        int intAlastDigit = (i >= 0) ? a[i] - '0' : 0;
        int intBlastDigit = (j >= 0) ? b[j] - '0' : 0;
        
        int carrySum = intAlastDigit + intBlastDigit + carry;
        // 繰り上がり判定
        carry = carrySum >= 2;
        carrySum %= 2;
        
        *resultEnd = carrySum + '0'; // '0' に変換
        resultEnd--;

        i--;
        j--;
    }

    // 先頭0である時削除（次の値が最後の文字でない場合）
    char* output = result;
    if (*output == '0' && *(output + 1) != '\0') {
        output++;
    }
    
    return output;
}

// コードサンプル
char* addBinary(char* a, char* b) {
    int i = strlen(a)-1, j = strlen(b)-1, carry = 0, sum = 0;
    int maxlength = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    char* result = (char*)malloc(maxlength + 2);
    int k = maxlength;
    result[k + 1] = '\0';
    while(i >= 0 || j >= 0 || carry)
    {
        sum = carry;
        if(i>=0) sum += a[i--] - '0';
        if(j>=0) sum += b[j--] - '0';
        result[k--]= sum % 2 + '0';
        carry = sum / 2;
    }
    return result + k + 1;
}