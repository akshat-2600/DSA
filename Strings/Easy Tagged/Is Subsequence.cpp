/*
    Company Tags        : 
    LeetCode Link       :   https://leetcode.com/problems/is-subsequence/

*/    

/************************************************************ C++ ************************************************************************/

//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n ? true : false;
    }
};


/************************************************************ JAVA ************************************************************************/

//T.C : O(n)
//S.C : O(1)

class Solution {
    public boolean isSubsequence(String s, String t) {
        int n = s.length();
        int m = t.length();

        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
            }
            j++;
        }
        return i == n ? true : false;
    }
}