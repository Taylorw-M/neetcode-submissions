class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //o(n) time so has to be hash
        //store each value o(n)
        //iterate through hash map count longest streak of consecutive sequence
        // if new consequitive sequence > record replace record

        //use map sort in log(n)
        map<int,int> hash;
        for(int i = 0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        if(hash.size() == 1){
            return 1;
        }
        int record = 0;
        int previous = 0;
        int count = 1;
        int i = 0;
        for (const auto& pair : hash) {
            if(i == 0){
                i = 1;
                previous = pair.first;
                continue;
            }
            if(pair.first == previous + 1){
                count++;
            } else {
                if(count>=record){
                record = count;
                count = 1;
                }
            }
            if(count>record){
                record = count;
            }
            previous = pair.first;
        }
        return record;
    }
};
