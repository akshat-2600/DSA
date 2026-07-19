/*
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/
*/


/************************************************************ C++ ************************************************************/

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();

        string result;

        vector<int> lastIndex(26);
        vector<bool> taken(26, false);

        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            int idx = ch - 'a';

            if (taken[idx] == true) {
                continue;
            }

            while (result.length() > 0 && result.back() > ch && lastIndex[result.back() - 'a'] > i) {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[idx] = true;
        }

        return result;
    }
};

/************************************************************ Java ************************************************************/

class Solution {
    public String smallestSubsequence(String s) {
        
        int n = s.length();

        StringBuilder result = new StringBuilder();

        int[] lastIndex = new int[26];
        boolean[] taken = new boolean[26];

        // Store the last occurence of each character
        for (int i=0; i < n; i++) {
            lastIndex[s.charAt(i) - 'a'] = i;
        }

        for (int i=0; i < n; i++) {
            char ch = s.charAt(i);
            int idx = ch - 'a';

            if (taken[idx]) {
                continue;
            }

            while (result.length() > 0 && 
                    result.charAt(result.length()-1) > ch &&
                    lastIndex[result.charAt(result.length()-1) - 'a'] > i) {

                taken[result.charAt(result.length()-1) - 'a'] = false;
                result.deleteCharAt(result.length()-1);
            }

            result.append(ch);
            taken[idx] = true;
        }

        return result.toString();
    }
}