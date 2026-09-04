/*  
    Company Tags         :  FACEBOOK
    GeeksForGeeks Link   :  https://www.geeksforgeeks.org/problems/bird-and-maximum-fruit-gathering--170645/1
*/

/****************************************************************** C++ ****************************************************/

// T.C  : O(n*m)
// S.C  : O(1)

class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        int maxSum = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int t = m;
            int j = i;
            
            while (t--) {
                sum += arr[j];
                j = (j+1) % n;
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};


// T.C  : O(n)
// S.C  : O(1)


class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        int maxSum = INT_MIN;
        int i = 0;
        int j = 0;
        int count = 0;
        int sum = 0;
        
        while (i < n) {
            sum += arr[j];
            count++;
            
            if (count == m) {
                maxSum = max(maxSum, sum);
                sum -= arr[i];
                i++;
                count--;
            }
            j = (j+1) % n;
        }
        return maxSum;
    }
};



