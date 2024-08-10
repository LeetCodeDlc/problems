/*

0ms
9.20MB

ループを2回回してしまっているのでもう少しいいやり方がありそうだけど思いつかなかった
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    bool allNine = true;

    // 全て9の場合を判別
    for(int i = digitsSize - 1; i >= 0; i--){
        if(digits[i] != 9){
            allNine = false;
            break;
        }
    }

    // 全ての数字が9の場合、桁数が1つ増える
    if(allNine == true){
        // digitsSize + 1分のメモリ確保
        int* result = (int*)malloc((digitsSize + 1) * sizeof(int));

        // 結果の配列生成
        result[0] = 1;
        for(int i = 1; i < digitsSize + 1; i++){
            result[i] = 0;
        }


        //戻り値の大きさを修正しないと呼び出し元でうまく処理できない
        *returnSize = digitsSize + 1;
        return result;
    } else {
        // メモリ確保
        int* result = (int*)malloc(digitsSize * sizeof(int));

        // 全て9以外のケースの処理
        int count = digitsSize - 1;

        // 9が連続する限り0を格納
        while(digits[count] == 9){
            result[count] = 0;
            count--;
        }
        // 9の連続が途絶えたら一番最初の数は+1する
        result[count] = digits[count] + 1;

        // 残りの数字は同じ
        for(int i = 0; i < count; i++){
            result[i] = digits[i];
        }


        *returnSize = digitsSize;
        return result;
    }
}