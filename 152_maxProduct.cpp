#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int n = nums.size();
        int product = 0;
        int maxProduct = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                product = nums[i] * nums[j];
                maxProduct = std::max(product, maxProduct);
            }
        }

        return maxProduct;
    }
};