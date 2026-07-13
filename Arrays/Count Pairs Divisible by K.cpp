/*
    Company Tags                :  
    Leetcode Link               :  https://www.geeksforgeeks.org/problems/count-pairs-in-array-divisible-by-k/1



/**************************************************************** C++ ****************************************************************/

// Approach-1 (Brute Force)
// T.C : O(n^2)
// S.C : O(1)

class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        
        int n = arr.size();
        int count = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int a = arr[i];
                int b = arr[j];
                int sum = a+b;
                
                if (sum%k == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};


// Approach-2 
// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    int countKdivPairs(vector<int>& arr, int k) {

        vector<int> freq(k, 0);

        int count = 0;

        for (int num : arr) {

            int rem = num % k;

            int need = (k - rem) % k;

            count += freq[need];

            freq[rem]++;
        }

        return count;
    }
};


/**************************************************************** JAVA ****************************************************************/


// Approach-1 (Brute Force)
// T.C : O(n^2)
// S.C : O(1)

class Solution {
    public int countKdivPairs(int[] arr, int k) {

        int n = arr.length;
        int count = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int sum = arr[i] + arr[j];

                if (sum % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
}


// Approach-2 
// T.C : O(n)
// S.C : O(n)
class Solution {
    public int countKdivPairs(int[] arr, int k) {

        int[] freq = new int[k];

        int count = 0;

        for (int num : arr) {

            int rem = num % k;

            // Handle negative numbers (optional, useful in general)
            if (rem < 0)
                rem += k;

            int need = (k - rem) % k;

            count += freq[need];

            freq[rem]++;
        }

        return count;
    }
}