#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
       //for store seen value
       unordered_map<int, int> nonrepeat;

       for (int i = 0; i < nums.size(); ++i) {
           int answer = target - nums[i];

           //unordered_map did not find anything, will return end(), means last position+1. 
           if (nonrepeat.find(answer) == nonrepeat.end()) {
               nonrepeat[nums[i]] = i;
           }
           else {
               return vector<int> {nonrepeat[answer], i};
           }

       }
       return{};
   }
};