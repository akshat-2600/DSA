/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/maximum-alternating-sum-of-squares/description/

*/


/******************************************************** C++ ********************************************************/

// Approach : Sorting + GREEDY
// T.C   : O(n * log(n))
// S.C   : O(1)


class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        for(int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;

        int posNums = n % 2 == 1 ? n/2 + 1 : n/2;
        long long sum = 0;
        
        for (int j = 0; j < posNums; j++) {
            sum += (nums[j]*nums[j]);
        }

        cout << sum << endl;

        for (int k = posNums; k < n; k++) {
            sum -= (nums[k]*nums[k]);
        }

        return sum;
    }
};

