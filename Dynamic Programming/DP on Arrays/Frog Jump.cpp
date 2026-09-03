/*  
    Company Tags    : 
    Leetcode Link   :  https://leetcode.com/problems/construct-uniform-parity-array-i/description/
*/

/****************************************************************** C++ ****************************************************/


//T.C : O(3^n)
//S.C : O(3*n)
class Solution {
public:
    bool solve(int i, unordered_set<long> &st, int lastStone, int k, unordered_map<string, bool>& t) {
        //Base case
        if (i == lastStone) {
            return true;
        }

        string key = to_string(i) + "->" + to_string(k);

        if (t.find(key) != t.end()) {
            return t[key];
        }

        bool jump1 = false;
        bool jump2 = false;
        bool jump3 = false;

        if (k - 1 > 0 && st.find(i+k-1) != st.end()) {
            jump1 = solve(i + k - 1, st, lastStone, k - 1, t);
        }
        
        if (st.find(i+k) != st.end()) {
            jump2 = solve(i + k, st, lastStone, k, t);
        }
        
        if (st.find(i+k+1) != st.end()) {
            jump3 = solve(i + k + 1, st, lastStone, k + 1, t);
        }

        return t[key] = (jump1 || jump2 || jump3);
    }

    bool canCross(vector<int>& stones) {
        if (stones.size() > 1 && stones[1] != 1) {
            return false;
        }
        int n = stones.size();
        int lastStone = stones[n-1];
        unordered_set<long> st(stones.begin(), stones.end());
        unordered_map<string, bool> t;

        return solve(1, st, lastStone, 1, t);
    }
};


