class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Initialize two pointers and variables to track window size and deleted zeros
        int ptrL = 0, ptrR = 0, maxWindow = 0, maxDeleted = 0;

        // Iterate through the array using the right pointer
        for(int ptrR = 0; ptrR < nums.size(); ++ptrR){
            // If the current element is 0, increment the count of deleted zeros
            if(nums[ptrR] == 0){
                maxDeleted++;
            }

            // If more than one zero is in the current window, move the left pointer to shrink the window
            while(maxDeleted > 1){
                if(nums[ptrL] == 0){
                    maxDeleted--; // Reduce the count of deleted zeros as we move past a zero
                }
                ptrL++; // Move the left pointer to the right
            }

            // Calculate the maximum window length (excluding one zero) by updating maxWindow
            maxWindow = max(maxWindow, ptrR - ptrL);
        }

        // Return the maximum window length found
        return maxWindow;
    }
};

/*
Explanation with Picture:

Consider the array: [1, 1, 0, 1, 1, 0, 1, 1, 1]

We use two pointers, ptrL and ptrR, to represent the sliding window:

Initial state:

ptrL -> 0
ptrR -> 0
[1, 1, 0, 1, 1, 0, 1, 1, 1]

As ptrR moves to the right, it expands the window, and we keep track of zeros encountered:

Step 1:
ptrR moves to index 2 (nums[2] == 0)
Count of zeros (maxDeleted) = 1

Step 2:
ptrR moves to index 5 (nums[5] == 0)
Count of zeros (maxDeleted) = 2
Since maxDeleted > 1, ptrL will move right to reduce the window size:

ptrL -> 3

Updated state:
ptrL at index 3
ptrR at index 5

Continue expanding the window until ptrR reaches the end, while ensuring only one zero is deleted in the current window. The goal is to find the largest possible window length (excluding one zero).

Final result:
The longest subarray with at most one zero deleted is of length 5.
*/