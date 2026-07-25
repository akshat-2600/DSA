/*
    Company Tags         :  
    LeetCode Link        :   https://leetcode.com/problems/merge-strings-alternately/description
*/


/**************************************************************** C++ ****************************************************************/

// Approach : n Two Pointers
// T.C      : O(max(len(word1), len(word2)))
// S.C      : O(1)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";

        int i = 0;
        int j = 0;

        while (i < word1.length() && j < word2.length()) {
            result.push_back(word1[i]);
            result.push_back(word2[j]);
            i++;
            j++;
        }
        while (i < word1.length()) {
            result.push_back(word1[i]);
            i++;
        }
        while (j < word2.length()) {
            result.push_back(word2[j]);
            j++;
        }

        return result;
    }
};

/**************************************************************** JAVA ****************************************************************/

// Approach : n Two Pointers
// T.C      : O(max(len(word1), len(word2)))
// S.C      : O(1)


class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder result = new StringBuilder();
        int i = 0;
        int j = 0;

        while (i < word1.length() && j < word2.length()) {
            result.append(word1.charAt(i));
            result.append(word2.charAt(j));
            i++;
            j++;
        }

        while (i < word1.length()) {
            result.append(word1.charAt(i));
            i++;
        }

        while (j < word2.length()) {
            result.append(word2.charAt(j));
            j++;
        }

        return result.toString();
    }
}