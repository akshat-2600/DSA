/*
    Company Tags         :   
    GeeksForGeeks Link   :   https://www.geeksforgeeks.org/problems/adding-ones3628/1

*/


/******************************************************** C++ ********************************************************/

// T.C   : O(n + k)
// S.C   : O(n)


class Solution {
  public:
    vector<int> update(int n, vector<int>& updates) {
        
        int m = updates.size();
        vector<int> freq(n);
        
        for (int i = 0; i < m; i++) {
            freq[updates[i]-1]++;
        }
        
        for (int j = 1; j < n; j++) {
            freq[j] += freq[j-1];
        }
        return freq;
    }
};

