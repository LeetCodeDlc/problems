/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i = 0; i < numsSize; i++){
        int sum = nums[i] + nums[i+1];
        if(sum == target){
            return returnSize = nums[i], nums[i+1];
        }
    }
}