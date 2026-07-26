/*
    Company Tags    :   
    LeetCode Link   :  https://leetcode.com/problems/greatest-common-divisor-of-strings/description
*/

/**************************************************************** C++ ****************************************************************/

// Approach : Brute Force 
// T.C      : O(min(n, m) * (n + m))
// S.C      : O(1)


class Solution {
public:
    bool check(string &s, string &pat) {
        int n = s.size();
        int m = pat.size();

        if (n % m != 0)
            return false;

        for (int i = 0; i < n; i += m) {
            if (s.substr(i, m) != pat)
                return false;
        }

        return true;
    }

    string gcdOfStrings(string str1, string str2) {

        int mn = min(str1.size(), str2.size());

        for (int len = mn; len >= 1; len--) {

            if (str1.size() % len || str2.size() % len)
                continue;

            string candidate = str1.substr(0, len);

            if (check(str1, candidate) && check(str2, candidate))
                return candidate;
        }

        return "";
    }
};

// Approach Optimal (Uisng gcd)
// T.C   : O(n + m)
// S.C   : O(n + m)

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if (str1 + str2 != str2 + str1)
            return "";

        int len = gcd((int)str1.size(), (int)str2.size());

        return str1.substr(0, len);
    }
};

/**************************************************************** JAVA ****************************************************************/

// Approach : Brute Force 
// T.C      : O(min(n, m) * (n + m))
// S.C      : O(1)

class Solution {

    private boolean check(String s, String pattern) {
        int n = s.length();
        int m = pattern.length();

        if (n % m != 0) {
            return false;
        }

        for (int i = 0; i < n; i += m) {
            if (!s.substring(i, i+m).equals(pattern)) {
                return false;
            }
        }
        return true;
    }

    public String gcdOfStrings(String str1, String str2) {
        
        int minLen = Math.min(str1.length(), str2.length());

        for (int len = minLen; len >= 1; len--) {

            if (str1.length() % len != 0 || str2.length() % len != 0) {
                continue;
            }

            String candidate = str1.substring(0, len);

            if (check(str1, candidate) && check(str2, candidate)) {
                return candidate;
            }
        }

        return "";
    }
}

// Approach Optimal (Uisng gcd)
// T.C   : O(n + m)
// S.C   : O(n + m)

class Solution {

    public String gcdOfStrings(String str1, String str2) {

        if (!(str1 + str2).equals(str2 + str1))
            return "";

        int len = gcd(str1.length(), str2.length());

        return str1.substring(0, len);
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}