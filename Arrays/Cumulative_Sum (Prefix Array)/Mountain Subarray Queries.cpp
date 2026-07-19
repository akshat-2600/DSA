/*
    Company Tags           : AMAZON 
    GFG Link               : https://www.geeksforgeeks.org/problems/mountain-subarray-problem/1
*/


/************************************************************ C++ ************************************************************/

// Approach : Brute force
// T.C : O(Q * N)
// S.C : O(1)

class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        vector<bool> ans;
        
        for (auto &q: queries) {
            int l = q[0];
            int r = q[1];
            
            int i = l;
            
            // Move while increasing
            while (i < r && arr[i] <= arr[i+1]) {
                i++;
            }
            
            // Move while decreasing
            while (i < r && arr[i] >= arr[i+1]) {
                i++;
            }
            
            ans.push_back(i == r);
        }
        return ans;
    }
};


// Approach : Precomputing furthest reachable index from i for both increasing and non decreasing arrays
// T.C : O(Q + N)
// S.C : O(2*N)

class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        
        int n = arr.size();
        
        // inc[i] = furthest index reachable from i while moving non-decreasing
        vector<int> inc(n);
        
        inc[n-1] = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] <= arr[i+1]) {
                inc[i] = inc[i+1];
            } else {
                inc[i] = i;
            }
        }
        
        // dec[i] = furthest index reachable from i while moving non-increasing
        vector<int> dec(n);
        
        dec[n-1] = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] >= arr[i+1]) {
                dec[i] = dec[i+1];
            } else {
                dec[i] = i;
            }
        }
        
        vector<bool> ans;
        
        for (auto& q : queries) {
            int start = q[0];
            int end   = q[1];
            
            int peak = inc[start];
            
            ans.push_back(dec[peak] >= end);
        }
        
        return ans;
    }
};

/************************************************************ Java ************************************************************/

// Approach : Brute force
// T.C : O(Q * N)
// S.C : O(1)

class Solution {
    public ArrayList<Boolean> processQueries(int[] arr, int[][] queries) {
        
        ArrayList<Boolean> ans = new ArrayList<>();
        
        for (int[] q: queries) {
            int l = q[0];
            int r = q[1];
            
            int i = l;
            
            // Move while non-decreasing
            while (i < r && arr[i] <= arr[i+1]) {
                i++;
            }
            
            // Move while non-increasing
            while (i < r && arr[i] >= arr[i+1]) {
                i++;
            }
            
            ans.add(i == r);
        }
        
        return ans;
        
    }
}

// Approach : Precomputing furthest reachable index from i for both increasing and non decreasing arrays
// T.C : O(Q + N)
// S.C : O(2*N)

class Solution {
    public ArrayList<Boolean> processQueries(int[] arr, int[][] queries) {
        
        int n = arr.length;
        
        // inc[i] = furthest index reachable from i while moving non-decreasing
        int[] inc = new int[n];
        
        inc[n-1] = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] <= arr[i+1]) {
                inc[i] = inc[i+1];
            } else {
                inc[i] = i;
            }
        }
        
        // dec[i] = futhest index reachable from i while moving non-increasing
        int[] dec = new int[n];
        
        dec[n-1] = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] >= arr[i+1]) {
                dec[i] = dec[i+1];
            } else {
                dec[i] = i;
            }
        }
        
        ArrayList<Boolean> ans = new ArrayList<>();
        
        for (int[] q : queries) {
            int start = q[0];
            int end   = q[1];
            
            int peak = inc[start];
            
            ans.add(dec[peak] >= end);
        }
        
        return ans;
    }
}