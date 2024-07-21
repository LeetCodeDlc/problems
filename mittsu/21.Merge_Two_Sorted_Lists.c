/**
3MS 
メモリ10.69MB

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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // ダミーノードを作成(これがないとNULLのメンバーを見に行ってしまいエラー発生)
    struct ListNode* dummyNode = createNode(0);
    struct ListNode* outputNode = dummyNode;

    //どちらも空になるまで繰り返し
    while(list1 != NULL || list2 != NULL) {
        //どちらかがNULLになった場合
        if (list1 == NULL) {
            outputNode->next = createNode(list2->val);
            list2 = list2->next;
        } else if (list2 == NULL) {
            outputNode->next = createNode(list1->val);
            list1 = list1->next;

        //どちらもNULLでない場合
        } else {
            //リスト1の先頭のほうが小さい場合、アウトプット用のノードに追加し、リスト1は次のノードに
            if (list1->val < list2->val) {
                outputNode->next = createNode(list1->val);
                list1 = list1->next;

            //リスト2の先頭のほうが小さい場合、アウトプット用のノードに追加し、リスト2は次のノードに
            } else {
                outputNode->next = createNode(list2->val);
                list2 = list2->next;
            }
        }

        //アウトプット用のノードを次のノードに移動
        outputNode = outputNode->next;
    }

    // ダミーノードの次のノードがマージされたリストの先頭
    struct ListNode* mergedList = dummyNode->next;
    //ダミーノードは解放
    free(dummyNode);  

    return mergedList;
}