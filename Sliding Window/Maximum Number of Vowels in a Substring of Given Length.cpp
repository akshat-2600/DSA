/*
    Company Tag       : 
    Leetcode Link     : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
*/


/*************************************************************** C++ *************************************************/

// T.C   : O(n*k)
// S.C   : O(1)  


class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
        int maxVowel = INT_MIN;

        for (int i = 0; i + k - 1 < s.length(); i++) {
            int count = 0;
            for (int j = 0; j < k; j++) {
                if (st.find(s[i+j]) != st.end()) {
                    count++;
                }
            }
            maxVowel = max(maxVowel, count);
        }
        return maxVowel;
    }
};

// T.C   : O(n)
// S.C   : O(1)  

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
        int maxVowel = INT_MIN;
        int n = s.length();
        
        int i = 0;
        int j = 0;
        int count = 0;

        while (j < n) {
            if (st.find(s[j]) != st.end()) {
                count++;
            }

            if (j-i+1 == k) {
                maxVowel = max(maxVowel, count);
                if (st.find(s[i]) != st.end()) {
                    count--;
                }
                i++;
            }
            j++;
        }
        return maxVowel;
    }
};