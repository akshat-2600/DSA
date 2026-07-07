/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/
*/


/**************************************************************** C++ ****************************************************************/

// T.C : O(n)
// S.C : O(1)

// using remainder

class Solution {
public:
    long long sumAndMultiply(int n) {
        int i = 1;
        long long sum = 0;
        int x = 0;
        
        while (n > 0) {
            int digit = n%10;
            n = n/10;
            
            if (digit == 0) continue;
            
            x += i*digit;
            i *= 10;
            sum += digit;
        }
        return x * sum;
    }
};


// Using String

// T.C : O(n)
// S.C : O(n)


class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        
        long long sum = 0;
        string x = "";
        for (char ch: s) {
            if (ch != '0') {
                x.push_back(ch);
                sum += ch - '0';
            }
        }
        if (x == "") {
            return 0;
        }
        return stoi(x) * sum;
    }
};


/**************************************************************** JAVA ****************************************************************/

// T.C : O(n)
// S.C : O(1)

// Using remainder

class Solution {
    public long sumAndMultiply(int n) {
        
        long place = 1;
        long sum = 0;
        long x = 0;

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit == 0) continue;

            x += place * digit;
            place *= 10;
            sum += digit;
        }

        return x * sum;
    }
}

// Using String

// T.C : O(n)
// S.C : O(n)

class Solution {
    public long sumAndMultiply(int n) {
        
        String s = String.valueOf(n);

        long sum = 0;
        StringBuilder x = new StringBuilder();

        for (char ch : s.toCharArray()) {
            if (ch != '0') {
                x.append(ch);
                sum += (ch - '0');
            }
        }

        if (x.length() == 0) {
            return 0;
        }

        long num = Long.parseLong(x.toString());

        return num * sum;
    }
}