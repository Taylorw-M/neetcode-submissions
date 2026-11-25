class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        vector<int> ans(temperatures.size());
        for(int i = 0; i<temperatures.size(); i++){
            if(s.empty()){
                s.push({temperatures[i], i});
                continue;
            }

            if(temperatures[i] > s.top().first){
                while(s.top().first < temperatures[i]){
                    ans.at(s.top().second) = (i - s.top().second); //pushes back difference
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
            }
            s.push({temperatures[i], i});
        }
        return ans;
    }
};
