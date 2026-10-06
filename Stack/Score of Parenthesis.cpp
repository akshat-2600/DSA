/** 
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/score-of-parentheses/

*/


/******************************************************** C++ ********************************************************/


//Approach 1 : Using Recrusion
//T.C        : O(n)
//S.C        : O(2*n)

class Solution {
public:
    int solve(int i, int j, vector<int>& endIdx) {
        int score = 0;

        while (i <= j) {
            if (endIdx[i] - i + 1 == 2) {
                score++;
                i += 2;
            } else if (endIdx[i] - i + 1 == 4) {
                score += 2;
                i = endIdx[i] + 1;
            } else {
                score += 2 * solve(i+1, endIdx[i] - 1, endIdx);
                i = endIdx[i] + 1;
            }
        }
        return score;
    }

    int scoreOfParentheses(string s) {
        int n = s.length();
        vector<int> endIdx(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == '(') {
                st.push(i);
            } else {
                endIdx[st.top()] = i;
                st.pop();
            }
        }

        return solve(0, n-1, endIdx);
    }
};



//Approach 2 : Using vector
//T.C        : O(n)
//S.C        : O(n)

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        vector<int> vec;

        int score = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == '(') {
                vec.push_back(score);
                score = 0;
            } else {
                if (s[i-1] == '(') {
                    score = vec.back() + 1;
                } else {
                    score = vec.back() + 2*score;
                }
                vec.pop_back();
            }
        }
        return score;
    }
};


//Approach 3 : Constant space
//T.C        : O(n)
//S.C        : O(1)

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                if (s[i-1] == '(') {
                    score += (1 << depth); // 2^depth
                }
            }
        }
        return score;
    }
};