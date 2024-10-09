class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptrLeft = 0;
        int ptrRight = 0;
        int temp;

        while(ptrRight < nums.size()){
            if(nums[ptrRight] != 0){
                temp = nums[ptrLeft];
                nums[ptrLeft] = nums[ptrRight];
                nums[ptrRight] = temp;

                ptrLeft++;
            }
            ptrRight++;
        }
    }
};