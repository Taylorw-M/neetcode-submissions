class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> prev(nums.size());
       vector<int> future(nums.size());
       size_t prev_total = 1;
       size_t future_total = 1;
       for(int i = 0; i<nums.size(); i++){
        //prev
        prev[i] = prev_total;
        prev_total *= nums[i];
        //future
        future[i] = future_total;
        future_total *= nums[nums.size() - 1 - i];
       }
       
       vector<int> ans(nums.size());
       for(int i = 0; i< nums.size(); i++){
        ans[i] = prev[i] * future[future.size() - 1 - i];
       }
       return ans;
    }
};
