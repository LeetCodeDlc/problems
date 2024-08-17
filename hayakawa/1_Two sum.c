/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i=0; i<numsSize; i=i+1){
        for(int j=i+1; j<numsSize; j=j+1){
            if(target == nums[i] + nums[j]){
                // 下記文は意味不明
                int* result = malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}