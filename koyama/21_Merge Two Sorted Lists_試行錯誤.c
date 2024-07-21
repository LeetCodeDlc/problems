/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
// リストのサイズを計算する関数
int getListSize(struct ListNode* head) {
    int size = 0;
    struct ListNode* current = head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //list1の配列のサイズを取得
    int lengthList1 = getListSize(list1);
    int lengthList2 = getListSize(list2);
    int k = 0;
    // printf("Length of list1: %d\n", lengthList1);
    // printf("list1のvalue: %d\n", list1[0].val);
    // printf("list1のvalue: %d\n", list1[4].val);
    // printf("list1のvalue: %d\n", list1[2].val);
    struct ListNode* output = (struct ListNode*)malloc((lengthList1 + lengthList2) * sizeof(struct ListNode));
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }
    // ListNodeの要素数分繰り返す
    for (int i = 0; i < lengthList1; i++){
        //printf("list1: %d, list2: %d\n", list1[0].val, list2[0].val);
        if (list1[i].val == NULL){
            output[k++] = 
            continue;
        }
        if (list2[i].val == NULL){
            output[k++] = list1[i];
            continue;
        }
        if(list1[i].val >= list2[i].val){
            //その時のoutputの配列に格納する必要がある。
            //outputの配列数を取得
            output[k++] = list1[i];
        }
        if(list2[i].val >= list1[i].val){
            //その時のoutputの配列に格納する必要がある。
            //outputの配列数を取得
            output[k++] = list2[i];
        }
    }
    //LIST2とlist1を比べて同じかそれ以下だったらOUSTPUTに格納
    return output;
}