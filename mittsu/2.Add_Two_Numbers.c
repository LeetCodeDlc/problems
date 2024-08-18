
/*
12MS
12.89MB
#21と#67を参考に作成

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 新しいノードを作成する関数
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// 2つの数を足し合わせる関数
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // ダミーノードを作成
    struct ListNode* dummyHead = createNode(0); 
    // 現在のノード
    struct ListNode* current = dummyHead; 
    //繰り上げの計算用
    int carry = 0; 

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry; 

        if (l1 != NULL) {
            sum += l1->val; 
            l1 = l1->next; 
        }

        if (l2 != NULL) {
            sum += l2->val; 
            l2 = l2->next; 
        }

        carry = sum / 10; 
        int digit = sum % 10; 

        //次のノード作成
        current->next = createNode(digit); 
        //currentを次のノードで置き換え
        current = current->next; 
    }

    //ダミーノードをスキップ
    struct ListNode* result = dummyHead->next; 
    // ダミーノードのメモリを解放
    free(dummyHead); 
    //結果を返す
    return result; 
}