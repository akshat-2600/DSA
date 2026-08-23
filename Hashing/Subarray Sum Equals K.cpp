/*
    Company Tags    :   FAMOUS
    LeetCode Link   :   https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/
*/


/**************************************************************** C++ ****************************************************************/

// Approach : Brute Force
// T.C      : O(n^2)
// S.C      : O(1)

#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

// Approach : Cummulative Sum + Hashing
// T.C      : O(n)
// S.C      : O(n)

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int cumSum = 0;
        int result = 0;

        for (int num : nums) {
            cumSum += num;

            if (mp.find(cumSum - k) != mp.end()) {
                result += mp[cumSum - k];
            } 
            mp[cumSum]++;
        }
        return result;
    }
};



/**************************************************************** JAVA ****************************************************************/

// comming soon
