/*
    Company Tag                 : 
    Leetcode Link               : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
*/


/*************************************************************** C++ *************************************************/

// Approach 1: Pure Recursion
// T.C       : O(2^n)
// S.C       : O(n)  (recursion call stack)

class Solution {
public:
    int solve(vector<int>& prices, int day, int n, bool buy) {
        if (day >= n) {
            return 0;
        }

        int profit = 0;

        if (buy) { // buy
            int take     = solve(prices, day+1, n, false) - prices[day]; // S.P - C.P
            int not_take = solve(prices, day+1, n, true);

            profit = max({profit, take, not_take});
        } else {  // sell
            int sell     = prices[day] + solve(prices, day+2, n, true);
            int not_sell = solve(prices, day+1, n, false);

            profit = max({profit, sell, not_sell});
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return solve(prices, 0, n, true);
    }
};

// Approach 2: Recursion + Memoization
// T.C       : O(n*2)
// S.C       : O(n)  


class Solution {
public:
    int t[5001][2];

    int solve(vector<int>& prices, int day, int n, bool buy) {
        if (day >= n) {
            return 0;
        }

        if (t[day][buy] != -1) {
            return t[day][buy];
        }

        int profit = 0;

        if (buy) {  // buy
            int take     = solve(prices, day+1, n, false) - prices[day];
            int not_take = solve(prices, day+1, n, true);

            profit = max({profit, take, not_take});
        } else {  // sell
            int sell     = prices[day] + solve(prices, day+2, n, true);
            int not_sell = solve(prices, day+1, n, false);

            profit = max({profit, sell, not_sell});
        }
        return t[day][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(t, -1, sizeof(t));

        return solve(prices, 0, n, true);
    }
};

// Approach 3: Bottom Up
// T.C       : O(n^2)
// S.C       : O(n)  


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n == 0 || n == 1) {
            return 0;
        }

        vector<int> t(n, 0);
        // t[i] = max profit at the end of ith day
        t[0] = 0;
        t[1] = max(prices[1] - prices[0], 0);  // max(bought_day_0 and sell_day_1, 0)

        for (int i = 2; i < n; i++) {
            t[i] = t[i-1]; // cool down

            // find best buy day from j = 0 to i-1
            for (int j = 0; j <= i-1; j++) {
                int prev_profit = j >= 2 ? t[j-2] : 0;

                t[i] = max(t[i], prices[i] - prices[j] + prev_profit);
            }
        }
        return t[n-1];
    }
};




/*************************************************************** JAVA *************************************************/

// coming soon 