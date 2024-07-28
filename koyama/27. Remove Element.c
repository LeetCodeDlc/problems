/* 
0ms
9.52MB
 */
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        // 現在の要素がvalと異なる場合
        if (nums[i] != val) { 
            // numsの次の値に格納
            nums[k++] = nums[i]; 
        }
    }
    return k;
}