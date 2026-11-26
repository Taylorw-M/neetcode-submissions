class Solution {
public:
    int maxProfit(vector<int>& prices) {
            int record = 0;
        for(int right = 0; right<prices.size(); right++){
            int left = 0;
            int profit = 0;
            while((left != right) && (right<prices.size())){
                profit = prices[right] - prices[left];
                if(profit > record){
                    record = profit;
                }
                left++;
            }
        }
        return record;
    }
};
