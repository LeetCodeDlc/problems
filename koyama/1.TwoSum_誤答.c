
/**
 * なんかiがすごい数になる"102049558"みたいな
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i = 0; i < numsSize; i++){
        int sum = nums[i] + nums[i+1];
        if(sum == target){
            int* result = (int*)malloc(2 * sizeof(int));
            result[0,1] = nums[i], nums[i+1];
            *returnSize = 2;
            return result;
        }
    }
    *returnSize = 0;
    return NULL;
}

