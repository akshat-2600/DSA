/** 
    Company Tags    :   
    LeetCode Link   :  https://leetcode.com/problems/remove-outermost-parentheses/description/

*/


/******************************************************** C++ ********************************************************/


//Approach : Using Stack
//T.C      : O(n)
//S.C      : O(n)

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;

        for (char ch : s) {
            if (ch == '(') {
                if (!st.empty()) {
                    ans.push_back(ch);
                }
                st.push(ch);
            } else {
                if (st.size() != 1) {
                    ans.push_back(ch);
                }
                st.pop();
            }
        }
        return ans;
    }
};
