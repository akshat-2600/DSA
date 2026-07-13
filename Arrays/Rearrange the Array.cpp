/*
    Company Tags                :  Flipkart
    Leetcode Link               :  https://www.geeksforgeeks.org/problems/rearrange-the-array-1639032648/1
*/


/**************************************************************** C++ ****************************************************************/

// Cycle detection --- T.C. O(n)
// GCD Calculation --- T.C. O(k*log(n))  , where k is the number of cyles



// T.C : O(n) 
// S.C : O(n)  

class Solution {
  public:
    int MOD = 1e9 + 7;
  
  
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
  
    int minOperations(vector<int> &b) {
        
        int n = b.size();
        vector<bool> visited(n, false);
        
        long long ans = 1;
        
        for (int i=0; i < n; i++) {
            if (!visited[i]) {
                int curr = i;
                int len = 0;
                
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = b[curr] - 1;
                    len++;
                }
                
                ans = (ans / gcd(ans, len)) * len;
            }
        }
        
        return ans % MOD;
        
    }
};



/**************************************************************** JAVA ****************************************************************/

// T.C : O(36) 
// S.C : O(1)  


class Solution {
    
    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    
    int minOperations(int[] b) {
        
        int n = b.length;
        boolean visited[] = new boolean[n];
        
        long ans = 1;
        
        for (int i=0; i < n; i++) {
            
            if (!visited[i]) {
                int curr = i;
                int len = 0;
                
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = b[curr] - 1; // convert to 0-based index
                    len++;
                }
                
                ans = (ans / gcd(ans, len)) * len;
            }
        }
        
        return (int)(ans % 1000000007);
    }
};