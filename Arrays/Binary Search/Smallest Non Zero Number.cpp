/*
    Company Tags                :  
    Leetcode Link               :  https://www.geeksforgeeks.org/problems/find-smallest-non-zero-number4510/1



/**************************************************************** C++ ****************************************************************/

// Approach 1: Binary Search + Simulation
// T.C : O(n*log(10^9))
// S.C : O(1)

class Solution {
  public:
    bool check(vector<int>& arr, long long x) {
        
        long long maxVal = 1e18;
        
        for (int a: arr) {
            x = 2LL * x - a;
            
            if (x < 0) {
                return false;
            }
            
            if (x > maxVal) x = maxVal;
        }
        return true;
    }
  
    int find(vector<int>& arr) {
        
        long long low  = 0;
        long long high = 1000000000;
        
        while (low <= high) {
            
            long long mid = low + (high - low)/2;
            
            if (check(arr, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
        
    }
};


// Approach 2: Reverse Greedy (Optimal)
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    int find(vector<int>& arr) {

        long long need = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            need = (need + arr[i] + 1) / 2;   // ceil((need + arr[i])/2)
        }

        return need;
    }
};

/**************************************************************** JAVA ****************************************************************/

// Approach 1: Binary Search + Simulation
// T.C : O(n*log(10^9))
// S.C : O(1)

class Solution {
    private boolean check(int[] arr, long x) {
        
        long MAX = (long) 1e18;
        
        for (int a: arr) {
            x = 2L * x - a;
            
            if (x < 0) {
                return false;
            }
            
            if (x > MAX) {
                x = MAX;
            }
        }
        return true;
    }
    
    public int find(int[] arr) {
        
        long low  = 0;
        long high = 1_000_000_000L;
        
        while (low <= high) {
            
            long mid = low + (high - low) / 2;
            
            if (check(arr, mid)) {
                high = mid - 1;
                
            } else {
                low = mid + 1;
            }
        }
        
        return (int) low;
    }
}


// Approach 2: Reverse Greedy (Optimal)
// T.C : O(n)
// S.C : O(1)

class Solution {
    public int find(int[] arr) {
        
        long need = 0;
        
        for (int i = arr.length-1; i >= 0; i--) {
            
            need = (need + arr[i] + 1) / 2;  // ceil((need + arr[i]) / 2)
        }
        return (int) need;
    }
}