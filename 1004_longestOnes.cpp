class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int L = 0, R = 0, maxWindow = 0, numZeros = 0;
        
        // Calculate prefix sum for the input array to facilitate range sum calculation
        vector<int> preSum = CalculatePrefixSum(nums);
        
        // Use sliding window to find the maximum window length with at most k zeros
        while (R < nums.size()) {
            // Calculate the sum of the current window [L, R]
            int tempSum = RangeSum(preSum, L, R);
            // Calculate the current window size
            int window = R - L + 1;
            
            // Calculate the number of zeros in the current window
            numZeros = window - tempSum;
            
            // If the number of zeros exceeds k, move the left pointer to reduce the window size
            if (numZeros > k) {
                L++;
            } else {
                // Otherwise, expand the right pointer to increase the window size
                R++;
                // Update the maximum window size found so far
                maxWindow = max(maxWindow, window);
            }
        }
        return maxWindow;
    }

    // Helper function to calculate prefix sum for the input array
    // Takes a constant reference to avoid copying the vector, ensuring better performance and preventing modification
    vector<int> CalculatePrefixSum(const vector<int>& arr) {
        vector<int> prefixSum(arr.size());
        prefixSum[0] = arr[0];
        
        // Calculate prefix sum where prefixSum[i] represents the sum of elements from index 0 to i
        for (size_t i = 1; i < arr.size(); ++i) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
        return prefixSum;
    }
    
    // Helper function to calculate the sum of the range [L, R] using prefix sum
    int RangeSum(const vector<int>& prefixSum, int L, int R) {
        if (L == 0) {
            // If L is 0, return prefixSum[R] directly
            return prefixSum[R];
        } else {
            // Otherwise, subtract prefixSum[L-1] from prefixSum[R] to get the range sum
            return prefixSum[R] - prefixSum[L - 1];
        }
    }
};

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int L = 0, R = 0, maxWindow = 0, numZeros = 0;
        
        while(R < nums.size()){
            if(nums[R] == 0){
                numZeros++;
            }

            while(numZeros > k){
                if(nums[L] == 0){
                    numZeros--;
                }
                L++;
            }
            maxWindow = max(maxWindow, R-L+1);
            R++;
        }
        return maxWindow;
    }
};