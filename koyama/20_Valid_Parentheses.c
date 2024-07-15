/* 
4ms
7.55 MB
 */

// 文字列の最後の文字を返す関数
char getLastChar(const char* str) {
    int length = strlen(str);
    if (length == 0) {
        return '\0'; // 空の文字列の場合は '\0' を返す
    }
    return str[length - 1];
}
// 文字列の最後の文字を削除する関数
void removeLastChar(char* str) {
    int length = strlen(str);
    if (length > 0) {
        str[length - 1] = '\0'; // 最後の文字をヌル文字に置き換える
    }
}

bool isValid(char* s) {

    int length = strlen(s);
    char* store = (char*)malloc((length + 1) * sizeof(char));
    store[0] = '\0'; // store を空の文字列として初期化
    bool result = false;

    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            int len = strlen(store);
            store[len] = s[i];
            store[len + 1] = '\0'; // 文字列の終端を示すnull文字を追加

        } else if ((s[i] == ')' && getLastChar(store) == '(') ||
                   (s[i] == ']' && getLastChar(store) == '[') ||
                   (s[i] == '}' && getLastChar(store) == '{')) {
            removeLastChar(store);
        } else {
            free(store);
            return false;
        }
    }
    // storeに文字が残っていた場合の判定
    if (strlen(store) != 0) {
        free(store);
        return false;
    }
    free(store);
    return true;
}