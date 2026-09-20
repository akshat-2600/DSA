/*
    Company Tags    :
    Leetcode Link   : https://leetcode.com/problems/reverse-degree-of-a-string/
*/

/************************************************************** C++ **************************************************************/

class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int j = 0; j < s.length(); j++) {
            int idx = s[j] - 'a';
            sum += (26 - idx) * (j+1);
        }
        return sum;
    }
};