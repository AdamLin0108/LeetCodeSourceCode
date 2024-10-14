class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> unorderNums1(nums1.begin(), nums1.end());
        unordered_set<int> unorderNums2(nums2.begin(), nums2.end());
        vector<vector<int>> result(2);

        for(int num : unorderNums1){
            if(unorderNums2.find(num) == unorderNums2.end()){
                result[0].push_back(num);
            }
        }
        for(int num : unorderNums2){
            if(unorderNums1.find(num) == unorderNums1.end()){
                result[1].push_back(num);
            }
        }

        return result;
    }
};