/*
    Company Tags                : Amazon
    Leetcode Link               : https://www.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1?_gl=1*jur5w7*_up*MQ..&gclid=Cj0KCQiA49XMBhDRARIsAOOKJHZRNAAZienXIkpogHQ2I3rSfKT8IT3jVQg1bi2cDPURBt5pGJnkMM8aAgqDEALw_wcB&gbraid=0AAAAAC9yBkBLKTbB4j8YDewdZI2chGPOg
*/


/**************************************************************** C++ ****************************************************************/

// T.C : O(n + m)
// S.C : O(1)

class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int i = 0,  j = 0;
        int n = a.size();
        int m = b.size();
        
        int sumA = 0, sumB = 0;
        int ans = 0;
        
        while (i < n && j < m) {
             
            if (a[i] > b[j]) {
                sumB += b[j];
                j++;
                
            } else if (a[i] < b[j]) {
                sumA += a[i];
                i++;
                
            } else {  // a[i] == b[j]  common element
                ans += max(sumA, sumB) + a[i]; // or b[j]
                sumA = 0;
                sumB = 0;
                i++;
                j++;
            }
        }
        
        while (i < n) {
            sumA += a[i];
            i++;
        }
        
        while (j < m) {
            sumB += b[j];
            j++;
        }
        
        ans += max(sumA, sumB);
        return ans;
        
    }
};


/**************************************************************** JAVA ****************************************************************/

// T.C : O(n + m)
// S.C : O(1)

class Solution {
    public int maxPathSum(int[] a, int[] b) {
        int i = 0;
        int j = 0;
        
        int n = a.length;
        int m = b.length;
        
        int sumA = 0;
        int sumB = 0;
        int ans  = 0;
        
        while (i < n && j < m) {
            
            if (a[i] < b[j]) {
                sumA += a[i];
                i++;
                
            } else if (a[i] > b[j]) {
                sumB += b[j];
                j++;
                
            } else { // a[i] == b[j]  common element
                ans += Math.max(sumA, sumB) + a[i];
                sumA = 0;
                sumB = 0;
                i++;
                j++;
                
            }
        }
        
        while (i < n) {
            sumA += a[i];
            i++;
        }
        
        while (j < m) {
            sumB += b[j];
            j++;
        }
        
        ans += Math.max(sumA, sumB);
        return ans;
    }
}
