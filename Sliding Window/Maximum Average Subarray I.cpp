/*
    Company Tag          : 
    Leetcode Link        : https://leetcode.com/problems/maximum-average-subarray-i/description/
*/


/*************************************************************** C++ *************************************************/

// T.C   : O(n*k)
// S.C   : O(1)  


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;

        for (int i = 0; i + k - 1 < nums.size(); i++) {
            int sum = 0;
            for (int j = 0; j < k; j++) {
                sum += nums[j+i];
            }
            double avg = (double)sum / k;
            if (avg > maxAvg) {
                maxAvg = avg;
            }
        }
        return maxAvg;
    }
};


// T.C   : O(n)
// S.C   : O(1)  

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;

        int count = 0;
        int sum   = 0;
        int idx = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            count++;
            if (count == k) {
                double avg = (double)sum / k;
                if (maxAvg < avg) {
                    maxAvg = avg;
                }
                count--;
                sum -= nums[idx++];
            }
        }
        return maxAvg;
    }
};

