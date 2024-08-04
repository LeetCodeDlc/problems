int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    //二分探索左と右が一致するまで探索
    while(left <= right){
        //midは小数点切り捨て
        int mid = (left + right)/2;
        int midNum = nums[mid];

        //midと一致したらインデックスを返す
        if(target == midNum){
            return mid;

        //targetがmidNumより大きければleftにmid+1代入
        }else if(midNum < target){
            left = mid + 1;
            
        //targetがmidNumより小さければrightにmid-1代入
        }else{
            right = mid - 1;
        }

    }
    //一致する数値がなければ最終的なleftのインデックスを返す
    return left;

}