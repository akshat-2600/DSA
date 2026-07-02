/*
    Company Tags                : 
    Leetcode Link               : https://www.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m2546/1?_gl=1*bd4mrp*_up*MQ..&gclid=Cj0KCQiA49XMBhDRARIsAOOKJHZRNAAZienXIkpogHQ2I3rSfKT8IT3jVQg1bi2cDPURBt5pGJnkMM8aAgqDEALw_wcB&gbraid=0AAAAAC9yBkBLKTbB4j8YDewdZI2chGPOg

/************************************************************ C++ ************************************************************************/

// T.C : O(2^n)
// S.C : O(1)
// Stack space : O(n)

// Recursion

class Solution {
  public:
    bool solve(vector<int>& arr, int k, int curr_sum, int idx, bool picked) {
        //Base case : reached the end of array
        if (idx == arr.size()) {
            return picked && (curr_sum % k == 0);
        }
        
        // Option 1: Do not include the current element
        bool exclude = solve(arr, k, curr_sum, idx+1, picked);
        
        //Option 2: Include the current element
        bool include = solve(arr, k, curr_sum + arr[idx], idx+1, true);
        
        return exclude || include;
    }
  
  
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        return solve(arr, k, 0, 0, false);
    }
};


// T.C : O(n * k)
// S.C : O(1)
// Stack Space : O(n)

// Recursion + Memoization

class Solution {
  public:
    int t[1001][1001][2];
  
    bool solve(vector<int>& arr, int k, int curr_rem, int idx, bool picked) {
        //Base case : reached the end of array
        if (idx == arr.size()) {
            return picked && (curr_rem == 0);
        }
        
        if (t[curr_rem][idx][picked] != -1) {
            return t[curr_rem][idx][picked];
        }
        
        // Option 1: Do not include the current element
        bool exclude = solve(arr, k, curr_rem, idx+1, picked);
        
        // Option 2: Include the current element
        
        // (curr_rem + arr[idx] % k can be negative in c++ so we normalize it
        
        int next_rem = (curr_rem + arr[idx]) % k;
        if (next_rem < 0) next_rem += k;
        
        bool include = solve(arr, k, next_rem, idx+1, true);
        
        return t[curr_rem][idx][picked] = exclude || include;
    }
  
  
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        memset(t, -1, sizeof(t));
        return solve(arr, k, 0, 0, false);
    }
};




/************************************************************ JAVA ************************************************************************/

// T.C : O(2^n)
// S.C : O(1)
// Stack space : O(n)

// Recursion

class Solution {
    
    public boolean solve(int[] arr, int k, int curr_sum, int idx, boolean picked) {
        // Base case: reached the end of array
        if (arr.length == idx) {
            return picked && (curr_sum % k == 0);
        }
        
        // Option 1: Do not include the current element
        boolean exclude = solve(arr, k, curr_sum, idx+1, picked);
        
        // Option 2: Include the current element
        boolean include = solve(arr, k, curr_sum + arr[idx], idx+1, true);
        
        return exclude || include;
    }
    
    public boolean divisibleByK(int[] arr, int k) {
        
        return solve(arr, k, 0, 0, false);
        
    }
}

