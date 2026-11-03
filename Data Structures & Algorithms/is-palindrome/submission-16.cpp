#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        if (s.empty()) {
            return true;
        }

        string::iterator L = s.begin();
        string::iterator R = s.end() - 1;

        while (L < R) {

            // Skip non-alphanumeric characters from left
            while (L < R && !isalnum(*L)) {
                L++;
            }

            // Skip non-alphanumeric characters from right
            while (L < R && !isalnum(*R)) {
                R--;
            }

            // Compare characters ignoring capitalization
            if (tolower(*L) != tolower(*R)) {
                return false;
            }

            L++;
            R--;
        }

        return true;
    }
};