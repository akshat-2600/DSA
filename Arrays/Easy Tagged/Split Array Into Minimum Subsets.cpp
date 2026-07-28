/*
    Company Tags   : 
    LeetCode Link  :  https://www.geeksforgeeks.org/problems/split-array-into-minimum-subsets/1

/************************************************************ C++ ************************************************************/


// Approach : Sorting the elements and then finding minimum subsets
// T.C      : O(n * log(n))
// S.C      : O(1)

class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        int count = 1;
        int num = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            if (num+1 == arr[i]) {
                num = arr[i];
            } else {
                count++;
                num = arr[i];
            }
        }
        return count;
    }
};



/************************************************************ Java ************************************************************/

// Approach : Sorting the elements and then finding minimum subsets
// T.C      : O(n * log(n))
// S.C      : O(1)


class Solution {
    int minSubsets(int arr[]) {
        
        Arrays.sort(arr);
        
        int count = 1;
        int num   = arr[0];
        
        for(int i = 1; i < arr.length; i++) {
            if (num + 1 == arr[i]) {
                num = arr[i];
            } else {
                count++;
                num = arr[i];
            }
        }
        return count;
    }
}