class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ptrL = 0;
        int ptrR = nums.size() - 1;
        int cnt = 0;

        // Need to sort the array, because use two pointer the Right one is the biggest num
        // that can control the Left and Right to correct position
        // Time complexity is O(nlogn), because use sort method
        // Space complexity is O(1)
        // Also can use hashmap to solve this problem
        // but the space complexity will greater than two pointer, 
        // the time complexity will smaller than two pointer
        sort(nums.begin(), nums.end());
        
        while(ptrL < ptrR){
            if(nums[ptrL] + nums[ptrR] == k){
                cnt++;
                ptrL++;
                ptrR--;
            }else if(nums[ptrL] + nums[ptrR] > k){
                ptrR--;
            }
            else{
                ptrL++;
            }
        }
        return cnt;
    }
};