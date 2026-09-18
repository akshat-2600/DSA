/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/description/
*/


/******************************************************** C++ ********************************************************/

// Approach : Greedy + Two Pointers
// T.C      : O(n)
// S.C      : O(26)


class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        vector<int> start(26, -1);
        vector<int> end(26, -1);
        vector<bool> isValid(26, true);

        vector<string> result;

        // marking start and end index of each character
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            if (start[idx] == -1) {
                start[idx] = i;
            }
            end[idx] = i;
        }

        for (int c = 0; c < 26; c++) { // checking all characters
            if (start[c] == -1) { // character does not exist in the strinh
                continue;
            }
            // checking in the range from start of char to end of char
            for (int i = start[c]; i <= end[c]; i++) {
                if (start[s[i] - 'a'] < start[c]) {
                    isValid[c] = false;
                    break;
                }
                end[c] = max(end[c], end[s[i] - 'a']);
            }
        }

        int lastTakenStart = INT_MAX;

        // building answer by iterating from right to left as 
        // this will help build smallest string and non overlapping
        for (int i = n-1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (!isValid[c]) {
                continue;
            }

            if (i == start[c] && end[c] < lastTakenStart) {
                result.push_back(s.substr(i, end[c] - i + 1));
                lastTakenStart = i;
            }
        }
        return result;
    }
};