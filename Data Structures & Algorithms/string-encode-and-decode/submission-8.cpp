class Solution {
public:
    string encode(vector<string>& strs) {
        string front = to_string(strs.size()) + "A";
        string back = "";

        for (int i = 0; i < strs.size(); i++) {
            int count = 0;

            for (int j = 0; j < strs[i].size(); j++) {
                back += "C" + to_string(
                    static_cast<int>(
                        static_cast<unsigned char>(strs[i][j])
                    )
                );
                count++;
            }

            front += "B" + to_string(count);
        }

        return front + back;
    }

    vector<string> decode(string s) {
        int i = 0;
        string curr = "";

        // Read the number of words before A.
        while (i < s.size() && s[i] != 'A') {
            curr += s[i];
            i++;
        }

        int words = stoi(curr);
        i++;  // Skip A.

        // Read each word's length after B.
        vector<int> word_count;

        for (int j = 0; j < words; j++) {
            i++;  // Skip B.
            curr = "";

            while (i < s.size() && s[i] != 'B' && s[i] != 'C') {
                curr += s[i];
                i++;
            }

            word_count.push_back(stoi(curr));
        }

        // Read the character codes for each word.
        vector<string> ans;

        for (int j = 0; j < words; j++) {
            string word = "";

            for (int k = 0; k < word_count[j]; k++) {
                i++;  // Skip C.
                curr = "";

                while (i < s.size() && s[i] != 'C') {
                    curr += s[i];
                    i++;
                }

                int ch = stoi(curr);
                word += static_cast<char>(ch);
            }

            ans.push_back(word);
        }

        return ans;
    }
};