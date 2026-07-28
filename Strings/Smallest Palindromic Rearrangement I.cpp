/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/
*/


/**************************************************************** C++ ****************************************************************/

// Approach : By reversing string 
// T.C      : O(n*log(n))
// S.C      : O(mid)

class Solution {
public:
    string rev(string s) {
        string temp = "";

        for (int i = s.length() - 1; i >= 0; i--) {
            temp += s[i];
        }
        return temp;
    }

    string smallestPalindrome(string s) {
        int n = s.length();

        if (n == 1) {
            return s;
        }

        string half = s.substr(0, n/2);

        sort(half.begin(), half.end());

        string rev_half = rev(half);

        if (n % 2 != 0) {
            char extra = s[n / 2];
            return half + extra + rev_half;
        } else {
            return half + rev_half;
        }
        return "";
    }
};

// Approach : Finding substring up to mid and them sorting them and then using same up to mid elements to add
// T.C      : O(n*log(n))
// S.C      : O(1) 

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();

        int mid = n / 2;

        sort(begin(s), begin(s) + mid);

        for (int i = 0; i < mid; i++) {
            s[n - i - 1] = s[i];
        }

        return s;
    }
};

/**************************************************************** JAVA ****************************************************************/


// Approach : Finding substring up to mid and them sorting them and then using same up to mid elements to add
// T.C      : O(n*log(n))
// S.C      : O(1) 

class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length();

        int mid = n / 2;

        char[] chars = s.toCharArray();

        Arrays.sort(chars, 0, mid);

        for (int i = 0; i < mid; i++) {
            chars[n - i - 1] = chars[i];
        }

        return new String(chars);
    }
}

// Approach : By reversing string 
// T.C      : O(n*log(n))
// S.C      : O(mid)

class Solution {

    String rev(String s) {
        String temp = "";

        for (int i = s.length() - 1; i >= 0; i--) {
            temp += s.charAt(i);
        }

        return temp;
    }

    public String smallestPalindrome(String s) {
        int n = s.length();

        if (n == 1) {
            return s;
        }

        String half = s.substring(0, n / 2);

        char[] halfChars = half.toCharArray();
        Arrays.sort(halfChars);
        String sortedHalf = new String(halfChars);

        String revHalf = new StringBuilder(sortedHalf).reverse().toString();

        if (n % 2 != 0) {
            char extra = s.charAt(n / 2);
            return sortedHalf + extra + revHalf;
        } else {
            return sortedHalf + revHalf;
        }
    }
}