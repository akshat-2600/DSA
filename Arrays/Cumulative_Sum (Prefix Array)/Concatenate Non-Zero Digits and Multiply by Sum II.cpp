/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/description/
*/


/**************************************************************** C++ ****************************************************************/

// Approach - Pre Storing all relevant data and using them
// T.C : O(n + q)
// S.C : O(n)

class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> nonZeroCount(n, 0);  // non-zero digit count in s[0...i]
        vector<ll> numberUpTo(n, 0);  // number formed from non-zero digits in s[0...i]
        vector<ll> digitSumUpTo(n, 0);  // digit sum of s[0...i]
        vector<ll> pow10(n+1, 0);  // 10^i

        pow10[0] = 1;
        for (int i=1; i <= n; i++) {
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
        for (int i=1; i < n; i++) {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i-1] + (digit != 0 ? 1 : 0);
        }

        numberUpTo[0] = s[0] - '0';
        for (int i=1; i < n; i++) {
            int digit = s[i] - '0';
            if (digit != 0) {
                numberUpTo[i] = (numberUpTo[i-1] * 10 + digit) % MOD;
            } else {
                numberUpTo[i] = numberUpTo[i-1];
            }
        }

        digitSumUpTo[0] = s[0] - '0'; 
        for (int i=1; i < n; i++) {
            digitSumUpTo[i] = digitSumUpTo[i-1] + (s[i] - '0');
        }

        int q = queries.size();
        vector<int> result(q);

        for (int i=0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            ll sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l-1]);

            int numBefore = (l == 0) ? 0 : numberUpTo[l-1];

            int k = nonZeroCount[r] - ((l == 0) ? 0 : nonZeroCount[l-1]);

            ll x = (numberUpTo[r] - (numBefore * pow10[k] % MOD) + MOD) % MOD;

            result[i] = (int)((x * sum) % MOD);
        } 
        return result;
    }
};


/**************************************************************** JAVA ****************************************************************/

// Approach - Pre Storing all relevant data and using them
// T.C : O(n + q)
// S.C : O(n)


class Solution {

    int MOD = 1000000007;

    public int[] sumAndMultiply(String s, int[][] queries) {
        int n = s.length();

        int[] nonZeroCount = new int[n];
        long[] numberUpTo = new long[n];
        long[] digitSumUpTo = new long[n];
        long[] pow10 = new long[n+1];

        // Precompute powers of 10
        pow10[0] = 1;
        for (int i=1; i <= n; i++) {
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        // Prefix count of non-zero digits
        nonZeroCount[0] = (s.charAt(0) != '0') ? 1 : 0;
        for (int i=1; i < n; i++) {
            int digit = s.charAt(i) - '0';
            nonZeroCount[i] = nonZeroCount[i-1] + (digit != 0 ? 1 : 0);
        }

        // Prefix number formed by non zero digit
        numberUpTo[0] = s.charAt(0) - '0';
        for (int i=1; i < n; i++) {
            int digit = s.charAt(i) - '0';

            if (digit != 0) {
                numberUpTo[i] = (numberUpTo[i-1] * 10 + digit) % MOD;
            } else {
                numberUpTo[i] = numberUpTo[i-1];
            }
        }

        // Prefix digit sum
        digitSumUpTo[0] = s.charAt(0) - '0';
        for (int i=1; i < n; i++) {
            digitSumUpTo[i] = digitSumUpTo[i-1] + (s.charAt(i) - '0');
        }

        int q = queries.length;
        int[] result = new int[q];

        for (int i=0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            long sum = digitSumUpTo[r] - (l == 0 ? 0 : digitSumUpTo[l-1]);

            long numBefore = (l == 0) ? 0 : numberUpTo[l-1];

            int k = nonZeroCount[r] - (l == 0 ? 0 : nonZeroCount[l-1]);

            long x = (numberUpTo[r] - (numBefore * pow10[k]) % MOD + MOD) % MOD;

            result[i] = (int)((x * sum) % MOD);
        }

        return result;
    }
}