int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);

    if (length == 0) {
        return 0;
    }

    // ダブりがない文字列を格納する用の配列
    char* CharsForCheck = (char*)malloc(length + 1);
    memset(CharsForCheck, 0, length + 1); // 配列を初期化

    // output用
    int maxLengthOfNoRepeatedChars = 0;
    // 一時保存用
    int LengthOfNoRepeatedChars = 0;

    // 最初の値は被りがないため
    CharsForCheck[0] = s[0];
    LengthOfNoRepeatedChars = 1;
    maxLengthOfNoRepeatedChars = 1;

    int i = 1; // sのインデックス
    int j = 1; // CharsForCheckのインデックス

    // １文字づつ被りチェックしていく
    while (i < length) {

        // CharsForCheckの要素数を取得
        int CharsForCheckLength = strlen(CharsForCheck);

        int isDuplicate = 0;    // ダブりがあったかどうかのフラグ
        int duplicateIndex = 0; // 重複が見つかった位置
        for (int k = 0; k < CharsForCheckLength; k++) {
            // もしダブりがあるなら
            if (CharsForCheck[k] == s[i]) {
                isDuplicate = 1;
                duplicateIndex = k;
                break;
            }
        }
        // ダブりがあった場合
        if (isDuplicate) {
            // 重複が見つかった位置までの部分文字列を切り詰める
            LengthOfNoRepeatedChars -= duplicateIndex + 1;
            // 重複が見つかった文字の次の位置から配列を更新
            for (int k = 0; k < CharsForCheckLength - duplicateIndex - 1; k++) {
                CharsForCheck[k] = CharsForCheck[duplicateIndex + 1 + k];
            }
            j = CharsForCheckLength - duplicateIndex - 1;
        }

        // ダブりがない場合
        // CharsForCheckに文字を格納
        CharsForCheck[j++] = s[i];
        LengthOfNoRepeatedChars++;

        // 最大長を更新
        if (LengthOfNoRepeatedChars > maxLengthOfNoRepeatedChars) {
            maxLengthOfNoRepeatedChars = LengthOfNoRepeatedChars;
        }

        i++;
    }
    return maxLengthOfNoRepeatedChars;
}