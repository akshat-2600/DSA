/** 
    Company Tags    :   
    LeetCode Link   :  https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

*/


/******************************************************** C++ ********************************************************/


//Approach 1 : Using Stack
//T.C        : O(n)
//S.C        : O(n)

class Solution {
public:
    int minAddToMakeValid(string s) {
        int score = 0;
        stack<char> st;
        
        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
            } else{
                if (st.empty()) {
                    score++;
                } else {
                    st.pop();
                }
            }
        }
        return score + st.size();
    }
};
