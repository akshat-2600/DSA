/*
    Company Tags                : Infosys
    Leetcode Link               : https://leetcode.com/problems/stone-game/
*/


/**************************************************************** C++ ****************************************************************/

//Approach : Greedy Filling the least rocks left to fill bag first
//T.C : O(n * log(n))
//S.C : O(n)

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int count = 0;

        vector<int> vec(n);

        for (int i=0; i < n; i++) {
            vec[i] = capacity[i] - rocks[i];
        }

        sort(vec.begin(), vec.end());

        for (int i = 0; i < n; i++) {
            if (additionalRocks >= vec[i]) {
                additionalRocks -= vec[i];
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};