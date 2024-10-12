#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> prefixSum(gain.size() + 1);

        prefixSum[0] = 0;
        
        for(int i = 1; i <= gain.size(); ++i){
            prefixSum[i] = prefixSum[i-1] + gain[i-1];
        }

        return *max_element(prefixSum.begin(), prefixSum.end());
    }
};

int main(){
    Solution s;
    vector<int> gain = {44,32,-9,52,23,-50,50,33,-84,47,-14,84,36,-62,37,81,-36,-85,-39,67,-63,64,-47,95,91,-40,65,67,92,-28,97,100,81};
    int res = s.largestAltitude(gain);
    cout << res << endl;
    return 0;
}