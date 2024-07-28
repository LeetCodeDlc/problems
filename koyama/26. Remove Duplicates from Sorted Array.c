/* 
16ms
11.84MB
 */

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    //最初の値は被りがないため
    int k = 1;
    for (int i = 1; i < numsSize; i++) {
        // 現在の要素が前の要素と異なる場合
        if (nums[i] != nums[i - 1]) { 
            // numsの次の値に格納
            nums[k++] = nums[i]; 
        }
    }
    return k;
}