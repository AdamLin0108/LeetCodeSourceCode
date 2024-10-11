class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int L = 0, R = 0, maxWindow = 0, numZeros = 0;
		
		vector<int> preSum = CalculatePrefixSum(nums);
		
		while(R < nums.size()){
			int tempSum = RangeSum(preSum, L, R);
			int window = R-L+1;
			
			numZeros = window - tempSum;
			
			if(numZeros > k){
				L++;
			} else {
				R++;
				maxWindow = max(maxWindow, window);
			}
			
		}
		return maxWindow;
    }

    vector<int> CalculatePrefixSum(const vector<int>& arr){
		vector<int> prefixSum(arr.size());
		prefixSum[0] = arr[0];
		
		for(size_t i = 1; i < arr.size(); ++i){
			prefixSum[i] = prefixSum[i-1] + arr[i];
		}
		return prefixSum;
	}
	
	int RangeSum(const vector<int>& prefixSum, int L, int R){
		if(L == 0){
			return prefixSum[R];
		} else{
			return prefixSum[R] - prefixSum[L-1];
		}
	}
};