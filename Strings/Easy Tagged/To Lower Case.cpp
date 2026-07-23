/*
    Company Tags                :  
    Leetcode Link               :  https://leetcode.com/problems/to-lower-case/description/
*/


/**************************************************************** C++ ****************************************************************/

// T.C : O(N)
// S.C : O(1)

class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";

        for (char ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                ans += ch + 32;
            } else {
                ans += ch;
            }
        }

        return ans;
    }
};


/**************************************************************** JAVA ****************************************************************/
 

// T.C : O(N^2)
// S.C : O(1)

class Solution {
    public String toLowerCase(String s) {
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (ch >= 'A' && ch <= 'Z') {
                ans.append((char)(ch + 32));
            } else {
                ans.append(ch);
            }
        }
        return ans.toString();
    }
}