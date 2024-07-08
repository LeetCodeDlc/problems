/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    //合計がtargetになるnums[i]とnums[j]を考える
    for (int i = 0; i < numsSize; i++){
        //重複をなくすため、ｊはiより大きいものとする
        for (int j = i + 1; j < numsSize; j++){

            //2つの数字の合計がtargetと一致する場合、[i,j]を返す
            if(nums[i] + nums[j] == target){
                int* arr = (int*)malloc(sizeof(i) + sizeof(j));
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
        }

    }
    //存在しない場合NULLを返す(これがないとコンパイルエラー)
    return NULL;
}
