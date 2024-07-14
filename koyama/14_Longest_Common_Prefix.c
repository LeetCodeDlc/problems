/*
4MS
8.17MB
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    // NULLの場合終了
    if (strs == NULL || strsSize == 0) {
        return NULL;
    }

    // メモリの割り当て
    int firstStrLength = strlen(strs[0]);
    char* output = (char*)malloc((firstStrLength + 1) * sizeof(char));
    if (output == NULL) {
        return NULL; // メモリ確保失敗時の処理
    }

    // 1つ目の文字列を格納
    strcpy(output, strs[0]);

    for (int i = 1; i < strsSize; i++) {
        if (strs[i] == NULL || strs[i] == "") {
            break;
        }
        //文字列の長さを格納
        int length = strlen(strs[i]);
        //temp_arrayにメモリ割り当て
        char* temp_array = (char*)malloc((firstStrLength + 1) * sizeof(char));
        if (temp_array == NULL) {
            free(output);
            return NULL; // メモリ確保失敗時の処理
        }
        // temp_arrayを初期化
        memset(temp_array, 0, (firstStrLength + 1) * sizeof(char));

        for (int j = 0; j < length; j++) {
            // それぞれの文字を比較し、合っていたら抽出
            if (strs[i][j] == output[j]) {
                temp_array[j] = strs[i][j];
            } else {
                break;
            }
        }
        // outputに格納
        strcpy(output, temp_array);
    }
    return output;
}