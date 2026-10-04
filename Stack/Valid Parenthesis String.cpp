/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/valid-parenthesis-string/description/

*/


/******************************************************** C++ ********************************************************/

// Approach : Using three stacks and valid parenthesis approach
// T.C      : O(n)
// S.C      : O(3*n)


class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int maxLen = 0;
        stack<pair<char, int>> st;
        unordered_map<int, int> mp; // idx, size

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == ')') {  // close
                if (st.empty()) {
                    continue;
                } else {
                    int openIdx = st.top().second;
                    st.pop();
                    if (mp.find(openIdx - 1) != mp.end()) {
                        int currLength = i - openIdx + 1 + mp[openIdx - 1];
                        mp[i] = currLength;
                        maxLen = max(maxLen, currLength);
                    } else {
                        int currLength = i - openIdx + 1;
                        mp[i] = currLength;
                        maxLen = max(maxLen, currLength);
                    }
                }
            } else {  // open
                st.push({ch, i});
            }
        }
        return maxLen;
    }
};