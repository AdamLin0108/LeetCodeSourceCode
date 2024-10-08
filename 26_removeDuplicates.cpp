#include <vector>

class Solution {
public:
   int removeDuplicates(std::vector<int>& nums) {
       if (nums.empty())
       {
           return 0;
       }
       int count = 0;
       for (int i = 0; i <= nums.size() - 1; i++)
       {
           if (nums[i] != nums[count])
           {
               count++;
               nums[count] = nums[i];
           }
       }
       return ++count;
   }
};