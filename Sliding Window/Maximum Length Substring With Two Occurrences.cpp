/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/
*/


/**************************************************************** C++ ****************************************************************/

// Approach : Sliding Window
// T.C      : O(n)
// S.C      : O(1)

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> vec(26, 0);

        int i = 0;
        int j = 0;
        int result = 0;

        while (j < n) {
            char ch1 = s[j];
            vec[ch1 - 'a']++;

            while (i < j && vec[ch1 - 'a'] > 2) {
                char ch2 = s[i];
                vec[ch2 - 'a']--;
                i++;
            }

            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};


/**************************************************************** JAVA ****************************************************************/

// Approach : Sliding Window
// T.C      : O(n)
// S.C      : O(1)

class Solution {
    public int maximumLengthSubstring(String s) {
        int n = s.length();
        int[] mp = new int[26];

        int i = 0;
        int j = 0;
        int result = 0;

        while (j < n) {
            char ch1 = s.charAt(j);
            mp[ch1 - 'a']++;

            while (i < j && mp[ch1 - 'a'] > 2) {
                char ch2 = s.charAt(i);
                mp[ch2 - 'a']--;
                i++;
            }

            result = Math.max(result, j - i + 1);
            j++;
        }
        return result;
    }
}