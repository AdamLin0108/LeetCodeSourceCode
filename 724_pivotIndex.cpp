#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Function to find the pivot index such that the sum of elements on the left is equal to the sum on the right
    int pivotIndex(vector<int>& nums) {
        vector<int> sumL, sumR;
        int len = nums.size();
        
        // Calculate prefix sum from left to right
        sumL = CalculatePrefixSum(nums);
        
        // Reverse the array to calculate prefix sum from right to left
        reverse(nums.begin(), nums.end());
        sumR = CalculatePrefixSum(nums);
        
        // Reverse back to original order for comparison purposes
        // We need to restore the original order of the array and the right prefix sum
        // to correctly compare the left and right prefix sums at each index
        reverse(nums.begin(), nums.end());
        reverse(sumR.begin(), sumR.end());
        
        // Check if there is an index such that left and right prefix sums are equal
        for(int i = 0; i < len; ++i){
            if(sumL[i] == sumR[i]) {
                return i;
            }
        }
        return -1; // Return -1 if no such index exists
    }

    // Helper function to calculate prefix sum for an array
    vector<int> CalculatePrefixSum(const vector<int>& arr){
        vector<int> PrefixSum(arr.size());
        PrefixSum[0] = arr[0];
        for(int i = 1; i < arr.size(); ++i){
            PrefixSum[i] = PrefixSum[i-1] + arr[i];
        }
        return PrefixSum;
    }
};

int main(){
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    // vector<int> nums = {2, 1, -1};
    // vector<int> nums = {1, 2, 3};
    Solution sol;
    cout << sol.pivotIndex(nums) << endl; // Output the pivot index
    return 0;
}

/*
Time Complexity Analysis:
- CalculatePrefixSum() runs in O(n) time, where n is the size of the input array.
- The pivotIndex() function involves:
  - Calculating prefix sums twice (left and right), each in O(n) time.
  - Reversing the array twice, each in O(n) time.
  - Iterating over the array to find the pivot, in O(n) time.
- Overall time complexity is O(n), as the operations are linear in terms of input size.

Space Complexity Analysis:
- Additional space is used to store the prefix sums (sumL and sumR), each requiring O(n) space.
- Thus, the overall space complexity is O(n).
*/


class Solution {
public:
    // Function to find the pivot index such that the sum of elements on the left is equal to the sum on the right
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0, leftSum = 0;
        int len = nums.size();
        
        // Calculate total sum of the array
        for (int num : nums) {
            totalSum += num;
        }
        
        // Iterate through the array and calculate left and right sums dynamically
        for (int i = 0; i < len; ++i) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }
        
        return -1; // Return -1 if no such index exists
    }
};

/*
Time Complexity Analysis:
- The pivotIndex() function involves:
  - Calculating the total sum in O(n) time.
  - Iterating over the array to find the pivot, in O(n) time.
- Overall time complexity is O(n), as the operations are linear in terms of input size.

Space Complexity Analysis:
- No additional space is used, resulting in O(1) space complexity.
*/