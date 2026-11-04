class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> sum;
        for(int i = 0; i< nums.size(); i++){
            sum[nums[i]].push_back(i);
        }

        for(int i = 0; i< nums.size(); i++){
            int j = 0;
            if(sum.find(target-nums[i]) != sum.end()){
                while((j <sum[target - nums[i]].size())&&( i == sum[target - nums[i]][j])){
                    j++;
                }
                if (j < sum[target - nums[i]].size()) {
                    return {i, sum[target - nums[i]][j]};
                }
            }
        }
        return{};
    }
};
