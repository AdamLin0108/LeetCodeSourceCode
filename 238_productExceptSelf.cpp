#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int ptrL, ptrR, leftPro = 1, rightPro = 1, pro = 1;
        vector<int> res(nums.size());
        int n = nums.size();

        for(int i = 0; i < n; ++i){
            ptrL = 0;
            ptrR = 0;
            leftPro = 1;
            rightPro = 1;
            pro = 1;
            
            if(ptrL >= 0){
                ptrL = i - 1;
            }
            if(ptrR < n-1){
                ptrR = i + 1;
            }
            
            while(ptrL >= 0){
                leftPro *= nums[ptrL];
                ptrL--;
            }
            while(ptrR < n){
                rightPro *= nums[ptrR];
                ptrR++;
            }

            pro = leftPro * rightPro;
            res[i] = pro;
        }
        return res;
    }
};
// time limit exceeded


int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> res = sol.productExceptSelf(nums);
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    return 0;
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, postfix = 1;
        int n = nums.size();
        vector<int> res(nums.size(), 1);

        // Calculate the prefix product for each element
        /*
         * Diagram for prefix calculation (using nums = [1, 2, 3, 4]):
         * nums:   [1, 2, 3, 4]
         * prefix:  1  1  2  6
         * res:     1  1  2  6
         */
        for(int i = 0; i < n; ++i){
            res[i] = prefix; // Set the result to the product of all previous elements
            prefix *= nums[i]; // Update the prefix product
        }
        
        // Calculate the postfix product for each element and multiply it with the result
        /*
         * Diagram for postfix calculation (using nums = [1, 2, 3, 4]):
         * nums:    [1, 2, 3, 4]
         * postfix:  24  12  4  1
         * res:      24  12  8  6
         */
        for(int i = n-1; i >= 0; --i){
            res[i] *= postfix; // Multiply the current result by the postfix product
            postfix *= nums[i]; // Update the postfix product
        }

        return res;
    }
};
