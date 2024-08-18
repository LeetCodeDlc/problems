
/**
 * ノードを反転させるメソッド
 */

struct ListNode* reverseAndCarry(struct ListNode* head) {
    // 新しいリストのためのダミーヘッド
    struct ListNode dummy;
    dummy.next = NULL;
    //bool carryFlg = false;

    //引数で渡されたノードの先頭を格納
    struct ListNode* current = head;
    while (current != NULL) {
        // 新しいノードを作成
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

        //current->valが10以上の場合数値を変える。
        //繰上げフラグを用意。
        printf("current: %d\n", current->val);
        if (carryFlg == true) {
            sum += 1;
            carryFlg = false;
        }
        if (sum >= 10) {
            carryFlg = true;
            sum -= 10;
        }
            newNode->val = current->val;
            // 一時ノードの向き先をダミーに変更
            newNode->next = dummy.next;
            // ダミーの向き先を一時ノードに向ける。
            dummy.next = newNode;
            // 元のリストの次のノードに進む
            current = current->next;
    }

    // ダミーヘッドの次のノードが反転されたリストの先頭
    return dummy.next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // dummy用のリスト作成
    struct ListNode dummy;
    // 最後のノードを指す
    struct ListNode* tail = &dummy;
    // NULLで初期化
    dummy.next = NULL;

    // l1とl2の末尾からを足し合わせていく
    while (l1 != NULL && l2 != NULL) {
        int sum = 0;
        sum = l1->val + l2->val;

        l1 = l1->next;
        l2 = l2->next;

        struct ListNode* tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        tempNode->val = sum;
        tempNode->next = NULL;
        tail->next = tempNode;
        tail = tail->next;
    }

    // 残りをリストに追加
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    //反転と繰上げ処理を行う
    struct ListNode* result = reverseAndCarry(dummy.next);
    return result;
}