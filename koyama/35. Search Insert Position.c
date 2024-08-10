/* 
6 ms
8.06 MB
 */

int searchInsert(int* nums, int numsSize, int target) {
    for (int i = 0; numsSize > i; i++){
        //同じ値だった時
        if(nums[i] == target){
            return i;
        }
        //targetがなかった時（途中）
        else if(nums[i] > target){
            return i;
        }
        //targetがなかった時（最後まで）
        else if(nums[numsSize - 1] < target){
            return numsSize;
        }
    }
    return 0;
}

//サンプルコード
int searchInsert(int* nums, int numsSize, int target) {
    //numsの先頭の要素を指す。（nums[0]）
    int *begin = nums;
    //numsの最後の指す（nums[最後]）
    int *end = nums + numsSize;

    
    while(nums < end) {
        //順にチェックしていく。
        if(*nums < target) nums += 1; 
        //
        else return nums - begin;
    }

    return numsSize;
}