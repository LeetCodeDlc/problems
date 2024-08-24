/** 
 *15ms
 *12.78MB
 */


/** 
 *リストの要素数を返す関数
 */
int getListLength(struct ListNode* head) {
    int length = 0;
    struct ListNode* current = head;
    
    // リストを走査して長さをカウント
    while (current != NULL) {
        length++;
        current = current->next;
    }
    
    return length;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int l1Stack[getListLength(l1)];
    int l2Stack[getListLength(l2)];
    int l1Top = -1;
    int l2Top = -1;

    while (l1 != NULL) {
        l1Stack[++l1Top] = l1->val; // スタックにプッシュ
        l1 = l1->next;
    }

    while (l2 != NULL) {
        l2Stack[++l2Top] = l2->val; // スタックにプッシュ
        l2 = l2->next;
    }

    // result用のリスト作成
    struct ListNode result;
    result.next = NULL;
    struct ListNode* current = &result;

    // 桁上がり処理用の判別フラグ
    bool carry = false;
    int i = 0;
    int j = 0;

    while (l1Top >= i || l2Top >= j || carry) {
        // 配列に値がない場合は0を代入
        int l1Value = (l1Top >= i) ? l1Stack[i] : 0;
        int l2Value = (l2Top >= j) ? l2Stack[j] : 0;
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        int carrySum = l1Value + l2Value + carry;

        // 繰り上がり判定
        carry = carrySum >= 10;
        carrySum %= 10;

        newNode->val = carrySum;
        newNode->next = NULL;

        current->next = newNode;
        current = newNode;

        i++;
        j++;
    }

    return result.next;
}