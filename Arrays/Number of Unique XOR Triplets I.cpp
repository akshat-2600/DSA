/*
    Company Tags                :  
    Leetcode Link               :  https://leetcode.com/problems/number-of-unique-xor-triplets-i/description/



/**************************************************************** C++ ****************************************************************/

// Approach : for n = 1 and 2 we get same answer as n but above this we always get answer when value is 2 power just less than greatest unique value
// T.C : O(log(n))
// S.C : O(1)

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1 || n == 2) {
            return n;
        }

        int ans = 1;
        while (ans <= n) {
            ans = ans << 1;
        }
        return ans;
    }
};



/**************************************************************** JAVA ****************************************************************/

// Approach : for n = 1 and 2 we get same answer as n but above this we always get answer when value is 2 power just less than greatest unique value
// T.C : O(log(n))
// S.C : O(1)

class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;

        if (n == 1 || n == 2) {
            return n;
        }

        int ans = 1;
        while (ans <= n) {
            ans = ans << 1;
        }

        return ans;
    }
}
