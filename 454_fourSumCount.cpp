class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> ABSumCounter, CDSumCounter;

        for(auto a : A){
            for(auto b : B){
                ABSumCounter[a+b] += 1;
            }
        }

        for(auto c : C){
            for(auto d : D){
                CDSumCounter[c+d] += 1;
            }
        }

        int ans = 0;
        for(auto abit = ABSumCounter.begin(); abit != ABSumCounter.end(); abit++){
            auto cdit = CDSumCounter.find(-abit->first);
            if(cdit != CDSumCounter.end()){
                //we are finding +`++combination, so use product
                ans += (abit->second * cdit->second);
            }
        }

        return ans;
    }
};