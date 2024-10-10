class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxProfit = 0;
        int profit = 0;

        while(right < prices.size()){
            if(prices[left] < prices[right]){
                profit = prices[right] - prices[left];
                maxProfit = max(profit, maxProfit);
            }
            else{
                left = right;
            }

            right++;
        }

        return maxProfit;
    }
};