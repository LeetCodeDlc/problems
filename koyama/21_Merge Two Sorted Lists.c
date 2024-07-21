/* 
3ms
10.74 MB
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // ダミーヘッドを使用して、新しいリストを作成
    struct ListNode dummy;
    // 最後のノードを指す（マージする位置を示すため）
    struct ListNode* tail = &dummy;
    //NULLで初期化
    dummy.next = NULL;

    // list1 と list2 をマージ
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        // 最後尾を移動させる
        tail = tail->next;
    }

    // 残りのリストを追加
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }
    //dummyのnextを返すことで、作成れたリストを返すことができる。
    return dummy.next;
}