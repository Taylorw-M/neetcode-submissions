class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> algo;
        for(int i = 0; i<strs.size(); i++){
            string word = strs[i];
            sort(word.begin(), word.end());
            algo[word].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (const auto& pair : algo){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
