class Solution {
public:
    /* seen problem before requires two pointers one at start one at end since they are increasing if the lowest value+highest value doesn't equal target highest value is impossible decrease highest (how to determine when lowest value is too low)
    [2,5,7,8] 12
    check if sum is higher or lower then target
    if lower increase bottom pointer 
    if higher decrease top pointer
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        int* pointbot = numbers.data();
        int* pointtop = numbers.data() + numbers.size() - 1;
        while(pointbot != pointtop){
            int valuebot = *pointbot;
            int valuetop = *pointtop;
            if(valuebot + valuetop == target){
                answer.push_back(pointbot - numbers.data()+1);
                answer.push_back(pointtop - numbers.data()+1);
                return answer;
            }
            if((valuebot + valuetop) > target){
                pointtop--;
            } else {
                pointbot++;
            }
        }
        return answer;
    }
};
