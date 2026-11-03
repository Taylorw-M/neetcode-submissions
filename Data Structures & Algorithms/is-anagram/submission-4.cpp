#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {//map one string then search with the other
        unordered_map<char,int> string1map;
        unordered_map<char,int> string2map;
        if(s.length() != t.length()){
            return false;
        }

        for(int i = 0; i<s.length(); i++){
            string1map[s[i]]++;
        }

        for(int i = 0; i<t.length(); i++){
            string2map[t[i]]++;
        }

        for (const auto& pair : string1map) {
            char character = pair.first;
            int value1 = pair.second;

            auto it = string2map.find(character);

            if (it == string2map.end() || value1 != it->second) {
                return false;
            }
        }
        return true;
    }
};
