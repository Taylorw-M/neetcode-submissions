class Solution {
public:
    bool isValid(string s) {
       unordered_map<char,char> brackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stak;
        for(int i = 0; i<s.length(); i++){
            if(!stak.empty()){
                if(stak.top() == brackets[s[i]]){
                    stak.pop();
                    continue;
                }
            }
            stak.push(s[i]); //skip this if pop
            
        }
        return stak.empty();
    }
};
