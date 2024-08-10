/**
 * 6ms
 * 9.36MB
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {

    int* output = (int*)malloc((digitsSize + 1) * sizeof(int));
    for (int i = 0; i < digitsSize; i++) {
        output[i] = digits[i];
    }

    int* end = output + digitsSize - 1;
    *end += 1;

    // 対象要素が10で桁が上がる時
    while (*end == 10 && end != output) {
        *end = 0;
        end--;
        *end += 1;
    }

    // 最後の要素の桁上がり処理
    if (*output == 10) {
        *output = 0;
        // 新しい配列にする
        for (int i = digitsSize; i > 0; i--) {
            output[i] = output[i - 1];
        }
        // 先頭に1を追加
        output[0] = 1;
        *returnSize = digitsSize + 1;
    } else {
        *returnSize = digitsSize;
    }

    return output;
}



// 以下サンプルコード
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = malloc(sizeof(int) * (digitsSize + 1));
    if (result == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    //メモリ操作関数
    memcpy(result + 1, digits, sizeof(int) * digitsSize); // 先に先頭に余白を持たせた配列を作る。
    result[0] = 0;
    int k = digitsSize;


    result[k] += 1;
    // 要素が10で配列が0以上の場合
    while (result[k] == 10 && k >= 0)
    {
        result[k--] = 0;
        result[k] += 1;
    }
    if (result[0] == 0)
    {
        *returnSize = digitsSize;
        return result + 1; // Leak here
    }
    else
    {
        *returnSize = digitsSize + 1;
        return result;
    }
}
