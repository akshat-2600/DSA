/*
    Company Tags         :   
    GeeksForGeeks Link   :   https://www.geeksforgeeks.org/problems/tricky-subset-problem1557/1
*/


/**************************************************************** C++ ****************************************************************/

// Approach : Greedy
// T.C      : O(n)
// S.C      : O(n)

class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        int n = arr.size();
        
        if (x == s) return true;
        
        vector<int> res(n+1, 0);
        long long sum = s;
        
        res[0] = s;
        
        for (int i = 0; i < n; i++) {
            long long next = sum + arr[i];
            res[i + 1] = next;
            sum += next;
        }
        
        long long remaining = x;
        
        for (int i = n; i >= 0; i--) {
            if (res[i] <= remaining) {
                remaining -= res[i];
            }
            
            if (remaining == 0) {
                return true;
            }
        }
        return false;
    }
};


/**************************************************************** JAVA ****************************************************************/

// Approach : Greedy
// T.C      : O(n)
// S.C      : O(n)


class Solution {
    public boolean isPossible(int[] arr, int s, int x) {
        int n = arr.length;
        if (x == s) return true;
        
        long[] res = new long[n+1];
        long sum = s;
        res[0] = s;
        
        for (int i = 0; i < n; i++) {
            long next  = sum + arr[i];
            res[i + 1] = next;
            sum += next;
        }
        
        long remaining = x;
        for (int i = n; i >= 0; i--) {
            if (res[i] <= remaining) {
                remaining -= res[i];
            }
            if (remaining == 0) {
                return true;
            }
        }
        return false;
    }
}