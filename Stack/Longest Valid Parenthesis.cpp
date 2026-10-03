/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/longest-valid-parentheses/description/

*/


/******************************************************** C++ ********************************************************/

/**
 * Approach :
 * Iterate from starting to end 
 * if you find a opening bracket simply push it into the stack
 * if you find a closing bracket then
 *            if stack is empty then continue
 *            else calculate open bracket index (openIdx) stored in stack and then pop the open bracket
 *                  if map contains openIdx - 1
 *                       store (currLen + (prevLen stored in map)) with closing bracket idx and calculate maxLen
 *                  else 
 *                       store currLen in map with closing bracket idx and calculate maxLen
 * return maxLen               
 */
// T.C   : O(n)
// S.C   : O(n)


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