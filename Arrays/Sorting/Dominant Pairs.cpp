/*
    Company Tags    :   
    Leetcode Link   :   https://www.geeksforgeeks.org/problems/dominant-pairs/1

*/


/******************************************************** C++ ********************************************************/

// Approach-1 : Brute Force
// T.C        : O(n^2)
// S.C        : O(1)

class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < n/2; i++) {
            for (int j = n/2; j < n; j++) {
                if (arr[i] >= (5 * arr[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};


// Approach-2 : Sorting
// T.C        : O(n * log(n))
// S.C        : O(1)

class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        
        int n = arr.size();
        sort(arr.begin(), arr.begin() + n/2);
        sort(arr.begin() + n/2, arr.end());
        int count = 0;
        int right = n / 2;
        
        for (int left = 0; left < n / 2; left++) {

            // Move right pointer while dominance condition holds
            while (right < n && arr[left] >= 5 * arr[right]) {
                right++;
            }
            // Count dominant pairs
            count += (right - n / 2);
        }
        return count;
    }
};