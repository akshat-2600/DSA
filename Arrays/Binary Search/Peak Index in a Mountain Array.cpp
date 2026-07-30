/*
    Company Tags   : 
    LeetCode Link  :  https://leetcode.com/problems/peak-index-in-a-mountain-array/

/************************************************************ C++ ************************************************************/

// Approach : Linear Search
// T.C      : O(n)
// S.C      : O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        for (int i = 0; i < arr.size(); i++) {
            if (i != 0 && arr[i-1] > arr[i]) {
                return i-1;
            }
        }
        return -1;
    }
};

// Approach : Two Pointers
// T.C      : O(n/2)
// S.C      : O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int n = arr.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            if (arr[l] < arr[l+1]) {
                l++;
            }

            if (arr[r] < arr[r-1]) {
                r--;
            }

            if (l == r) return l;
        }
        return -1;
    }
};

// Approach : Binary Search
// T.C      : O(log(n))
// S.C      : O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int n = arr.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] < arr[mid+1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

/************************************************************ Java ************************************************************/

// Approach : Linear Search
// T.C      : O(n)
// S.C      : O(1)

class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (i != 0 && arr[i-1] > arr[i]) {
                return i - 1;
            }
        }
        return -1;
    }
}

// Approach : Two Pointers
// T.C      : O(n/2)
// S.C      : O(1)

class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int n = arr.length;
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            if (arr[l] < arr[l+1]) {
                l++;
            }

            if (arr[r] < arr[r-1]) {
                r--;
            }

            if (l == r) {
                return l;
            }
        }
        return -1;
    }
}

// Approach : Binary Search
// T.C      : O(log(n))
// S.C      : O(1)

class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int n = arr.length;
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] < arr[mid+1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
}

