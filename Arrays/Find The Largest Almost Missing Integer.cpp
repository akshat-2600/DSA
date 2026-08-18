/*  
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/find-the-largest-almost-missing-integer/
*/


/********************************************************************* C++ ****************************************************************/

//Approach-1 - Brute force -> Count element occurrences in all subarrays of size k using brute force or sliding window.
//T.C : O(n * k)
//S.C : O(n)

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxNum = INT_MIN;

        if (nums.size() == k) {
            return *max_element(nums.begin(), nums.end());
        }

        for (int i=0; i + k <= nums.size(); i++) {
            for (int j = 0; j < k; j++) {
                int a = nums[i+j];
                mp[a]++;
            }
        }
        
        for (auto &[p, q] : mp) {
            if (q == 1) {
                maxNum = max(maxNum, p);
            }
        }

        return maxNum != INT_MIN ? maxNum : -1;
    }
};

//Approach-2 (Sliding Window)
// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        unordered_map<int, int> mp;
        //I will go to each subarray of size k (window of size k) and mark which element came in that subarray
        //In the end , I will see which element came in exactly 1 subarray
        
        unordered_set<int> st;
        while(j < n) {
            if(j-i+1 == k) { //k sized subarray

                //Collect which elements are in this window
                for(int l = i; l <= j; l++) {
                    st.insert(nums[l]);
                }
                
                //Mark those elements
                for(int x : st) {
                    mp[x]++;
                }

                st.erase(nums[i]); //shifting window
                i++;
            }
            j++;
        }

        int result = -1;

        //Find the largest element which appeared in one subarray only
        for(auto [num, count] : mp) {
            if(count == 1 && num > result) {
                result = num;
            }
        }

        return result;
        
    }
};

//Approach-3 (Simple Observation)
// T.C  : O(n)
// S.C  : O(1)

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        //case 1 : When k == n
        if(k == n) { //only one subarray possible. Select the largest element
            return *max_element(begin(nums), end(nums));
        }

        //case 2 : When k == 1
        int freq[51] = {0};
        for(int &num : nums) {
            freq[num]++;
        }

        if(k == 1) { //every index is one subarray. Find largest element which appears only once
            for(int num = 50; num >= 0; num--) {
                if(freq[num] == 1) {
                    return num;
                }
            }
            return -1;
        }

        //case 3 : 1 < k < n
        //Notice that only the first and last element are going to be the ones which will
        //appear only in one subarray. Others will be part of more than one subarray always
        
        int maxResult = -1;
        //So, if nums[0] appeared only at index 0, then it appeared only in one subarray
        if(freq[nums[0]] == 1) {
            maxResult = max(maxResult, nums[0]);
        }

        //Same, if nums[n-1] appeared only at index n-1, then it appeared only in one subarray
        if(freq[nums[n-1]] == 1) {
            maxResult = max(maxResult, nums[n-1]);
        }

        return maxResult;
    }
};


/********************************************************************* JAVA ****************************************************************/

//Approach-1 - Count element occurrences in all subarrays of size k using brute force or sliding window.
//T.C : O(n * k)
//S.C : O(n)


import java.util.HashMap;
import java.util.Map;

class Solution {
    public int largestInteger(int[] nums, int k) {
        // Base case: If array length equals k, return the maximum element
        if (nums.length == k) {
            int max = Integer.MIN_VALUE;
            for (int num : nums) {
                max = Math.max(max, num);
            }
            return max;
        }

        Map<Integer, Integer> counts = new HashMap<>();
        
        // Count elements in all subarrays of size k
        for (int i = 0; i <= nums.length - k; i++) {
            for (int j = 0; j < k; j++) {
                int currentElement = nums[i + j];
                counts.put(currentElement, counts.getOrDefault(currentElement, 0) + 1);
            }
        }

        int maxNum = Integer.MIN_VALUE;

        // Find the largest integer that appears exactly once across the tracked segments
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            if (entry.getValue() == 1) {
                maxNum = Math.max(maxNum, entry.getKey());
            }
        }

        return maxNum != Integer.MIN_VALUE ? maxNum : -1;
    }
}