#include<unordered_map>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size() == 0){
            return false;
        }

        unordered_map<int,int> mymap;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            curr = nums[i];
            if(mymap.find(curr) == mymap.end()){
                mymap[curr]++;
            } else {
                return true;
            }  
        }
        return false;
    }
};