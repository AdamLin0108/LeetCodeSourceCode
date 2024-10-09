#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        bool isMaximum;
        vector<bool> result;
        int temp = 0;

        for(int i = 0; i <= candies.size(); i++){
            temp = candies[i] + extraCandies;

            for (int j = i; j < i; j++){
                if(temp > candies[j]){
                    isMaximum = true;
                    result.push_back(isMaximum);
                }
                else{
                    isMaximum = false;
                    result.push_back(isMaximum);
                }
            }
            
        }
        return result;
    }
};