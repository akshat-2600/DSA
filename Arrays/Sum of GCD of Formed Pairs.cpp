/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/
*/


/******************************************************************** C++ ********************************************************************/



class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> ans;

        int mxi = INT_MIN;
        for (int i=0; i < nums.size(); i++) {
            mxi = max(nums[i], mxi);

            ans.push_back(__gcd(mxi, nums[i]));
        }

        sort(ans.begin(), ans.end());

        int i = 0;
        int j = ans.size() - 1;

        long long gcdSum = 0;

        while (i < j) {
            int a = ans[i];
            int b = ans[j];

            gcdSum += __gcd(a, b);
            i++;
            j--;
        }
        return gcdSum;
    }
};

/******************************************************************** JAVA ********************************************************************/

// T.C : O(N + log(N) + log(min(a, b)))
// S.C : O(N)

class Solution {
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public long gcdSum(int[] nums) {
        List<Integer> ans = new ArrayList<>();

        int mxi = Integer.MIN_VALUE;
        for (int i=0; i < nums.length; i++) {
            mxi = Math.max(mxi, nums[i]);

            ans.add(gcd(mxi, nums[i]));
        }

        Collections.sort(ans);

        int i = 0;
        int j = ans.size() - 1;

        long gcdSum = 0;

        while (i < j) {
            int a = ans.get(i);
            int b = ans.get(j);

            gcdSum += gcd(a, b);

            i++;
            j--;
        }

        return gcdSum;
    }
}