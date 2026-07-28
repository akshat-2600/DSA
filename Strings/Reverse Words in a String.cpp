/*
    Company Tags       : 
    Leetcode Link      :  https://leetcode.com/problems/reverse-words-in-a-string/description/
*/


/**************************************************************** C++ ****************************************************************/

// Appraoch : Without reversing
// T.C      : O(n ^ 2)
// S.C      : O(n)  

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result = "";;
        int i = n-1;
        while (i >= 0) {
            if (s[i] != ' ') {
                int idx = i;
                string word = "";
                while (idx >= 0 && s[idx] != ' ') {
                    word = s[idx] + word;
                    idx--;
                }
                
                if (result.empty()) {
                    result = word;
                } else {
                    result = result + " " + word;
                }
                i = idx;
            } else {
                i--;
            }
        }        
        return result;
    }
};


// Appraoch : With Reversing
// T.C      : O(n)
// S.C      : O(n)

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (word.length() > 0) {
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};



/**************************************************************** JAVA ****************************************************************/

// Appraoch : Without reversing
// T.C      : O(n ^ 2)
// S.C      : O(n)

class Solution {
    public String reverseWords(String s) {
        int n = s.length();
        StringBuilder result = new StringBuilder();
        int i = n - 1;
        
        while (i >= 0) {
            if (s.charAt(i) != ' ') {
                int idx = i;
                StringBuilder word = new StringBuilder();
                
                // Extract word maintaining correct character sequence
                while (idx >= 0 && s.charAt(idx) != ' ') {
                    word.insert(0, s.charAt(idx));
                    idx--;
                }
                
                // Append word to the final result string
                if (result.length() == 0) {
                    result.append(word);
                } else {
                    result.append(" ").append(word);
                }
                i = idx;
            } else {
                i--;
            }
        }
        return result.toString();
    }
}


// Appraoch : With Reversing
// T.C      : O(n)
// S.C      : O(n)


class Solution {
    public String reverseWords(String s) {
        int n = s.length();
        StringBuilder ans = new StringBuilder();
        
        // Reverse the entire string
        StringBuilder reversedS = new StringBuilder(s).reverse();
        
        for (int i = 0; i < n; i++) {
            StringBuilder word = new StringBuilder();
            
            // Extract the word
            while (i < n && reversedS.charAt(i) != ' ') {
                word.append(reversedS.charAt(i));
                i++;
            }
            
            // Reverse the individual word back to its original order
            word.reverse();
            
            // Append to the answer with a space if it's a valid word
            if (word.length() > 0) {
                ans.append(" ").append(word);
            }
        }
        
        // Return string skipping the leading space
        return ans.length() > 0 ? ans.substring(1) : "";
    }
}
