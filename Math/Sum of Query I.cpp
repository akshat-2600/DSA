/*
    Company Tags                : 
    Leetcode Link               : https://www.geeksforgeeks.org/problems/sum-of-query-i1920/1
*/


/**************************************************************** C++ ****************************************************************/

// T.C : O(N + Q)
// S.C : O(N)

class Solution {
public:
    int MOD = 1e9 + 7;

    vector<int> FindQuery(vector<int> nums, vector<vector<int>> Query) {

        int n = nums.size();

        vector<long long> pref1(n + 1, 0);
        vector<long long> pref2(n + 1, 0);
        vector<long long> pref3(n + 1, 0);

        // Array is considered 1-indexed
        for (int i = 1; i <= n; i++) {

            long long val = nums[i - 1];

            pref1[i] = (pref1[i - 1] + val) % MOD;

            pref2[i] = (pref2[i - 1] + val * (i + 1)) % MOD;

            pref3[i] = (pref3[i - 1] + val * (i + 1) * (i + 1)) % MOD;
        }

        vector<int> ans;

        for (auto &q : Query) {

            long long l = q[0];
            long long r = q[1];

            long long S1 = (pref1[r] - pref1[l - 1] + MOD) % MOD;
            long long S2 = (pref2[r] - pref2[l - 1] + MOD) % MOD;
            long long S3 = (pref3[r] - pref3[l - 1] + MOD) % MOD;

            long long res = (S3 - (2LL * l % MOD) * S2 % MOD + MOD) % MOD;
            res = (res + (l * l % MOD) * S1 % MOD) % MOD;

            ans.push_back((int)res);
        }

        return ans;
    }
};

/**************************************************************** JAVA ****************************************************************/

// T.C : O(N + Q)
// S.C : O(N)

class Solution {

    int MOD = 1000000007;

    public int[] FindQuery(int[] nums, int[][] Query) {

        int n = nums.length;

        long[] pref1 = new long[n + 1];
        long[] pref2 = new long[n + 1];
        long[] pref3 = new long[n + 1];

        // Build prefix sums
        for (int i = 1; i <= n; i++) {

            long val = nums[i - 1];

            pref1[i] = (pref1[i - 1] + val) % MOD;
            pref2[i] = (pref2[i - 1] + val * (i + 1)) % MOD;
            pref3[i] = (pref3[i - 1] + val * (i + 1) * (i + 1)) % MOD;
        }

        int q = Query.length;
        int[] ans = new int[q];

        for (int i = 0; i < q; i++) {

            long l = Query[i][0];
            long r = Query[i][1];

            long S1 = (pref1[(int) r] - pref1[(int) l - 1] + MOD) % MOD;
            long S2 = (pref2[(int) r] - pref2[(int) l - 1] + MOD) % MOD;
            long S3 = (pref3[(int) r] - pref3[(int) l - 1] + MOD) % MOD;

            long res = (S3 - (2L * l % MOD) * S2 % MOD + MOD) % MOD;
            res = (res + (l * l % MOD) * S1 % MOD) % MOD;

            ans[i] = (int) res;
        }

        return ans;
    }
}