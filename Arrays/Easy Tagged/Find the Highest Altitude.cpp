/*
    Company Tag          : 
    Leetcode Link        : https://leetcode.com/problems/find-the-highest-altitude/
*/


/*************************************************************** C++ *************************************************/

// T.C       : O(n)
// S.C       : O(1)  


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxGain = 0;
        int prevGain = 0;

        for (int i = 0; i < gain.size(); i++) {
            maxGain = max(maxGain, prevGain + gain[i]);
            prevGain = prevGain + gain[i];
        }
        return maxGain;
    }   
};

