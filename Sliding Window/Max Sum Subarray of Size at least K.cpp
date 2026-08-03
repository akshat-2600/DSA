/*
    Company Tags    :   FACEBOOK, PAYTM, MYNTRA
    LeetCode Link   :   https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1
*/


/**************************************************************** C++ ****************************************************************/


// Approach : Sliding window + while loop
// T.C : O(n^2)
// S.C : O(n)

class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        vector<int> prefSum(n+1, 0);
        
        for (int i=1; i <= n; i++) {
            prefSum[i] += arr[i-1] + prefSum[i-1];
        }
        
        int maxSum = INT_MIN;
        
        for (int i=1; i <= n; i++) {
            int j = i + k - 1;
            if (j > n) {
                break;
            }
            int currSum = prefSum[j] - (i-1 >= 0 ? prefSum[i-1] : 0);
            maxSum = max(maxSum, currSum);
            j++;
            while (j < n+1) {
                currSum += prefSum[j] - prefSum[j-1];
                maxSum = max(maxSum, currSum);
                j++;
            } 
        }
        return maxSum;
    }
};

// Approach : Optimized sliding window
// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {

        int n = arr.size();

        // maxSumEndingHere[i] = maximum subarray sum ending at i
        vector<int> maxSumEndingHere(n);

        maxSumEndingHere[0] = arr[0];
        for (int i = 1; i < n; i++) {
            maxSumEndingHere[i] = max(arr[i], maxSumEndingHere[i - 1] + arr[i]);
        }

        // First window of size k
        int windowSum = 0;
        for (int i = 0; i < k; i++)
            windowSum += arr[i];

        int ans = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {

            windowSum += arr[i];
            windowSum -= arr[i - k];

            // Exactly k elements
            ans = max(ans, windowSum);

            // More than k elements
            ans = max(ans, windowSum + maxSumEndingHere[i - k]);
        }

        return ans;
    }
};

/**************************************************************** JAVA ****************************************************************/

