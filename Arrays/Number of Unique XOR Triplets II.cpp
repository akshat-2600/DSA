/*
    Company Tags          :  
    LeetCode Link         :   https://leetcode.com/problems/number-of-unique-xor-triplets-ii/description/



/**************************************************************** C++ ****************************************************************/

// Approach : Using HashSet
// T.C      : O(n^2 + n * uniquePairsXors)
// S.C      : O(uniquePairXors + uniqueTripletXors)

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st1;

        // Store all Pair XORS
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                st1.insert(nums[i] ^ nums[j]);
            }
        }

        // Find triplet XORS
        unordered_set<int> st2;
        for (int val : st1) {
            for (int num : nums) {
                st2.insert(val ^ num);
            }
        }
        return st2.size();
    }
};

// Approach : Using Boolean Arrays
// T.C      : O(n^2 + T * n)
// S.C      : O(2*T)

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        int maxEle = *max_element(nums.begin(), nums.end());

        int T = 1;
        while (T <= maxEle) {
            T *= 2;
        }

        vector<bool> st1(T, false);
        vector<bool> st2(T, false);


        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int val = nums[i] ^ nums[j];
                st1[val] = true; 
            }
        }

        for (int i = 0; i < T; i++) {
            if (st1[i] == true) {
                for (int &num : nums) {
                    st2[i ^ num] = true;
                }
            }
        }

        int count = 0;
        for (int i=0; i < T; i++) {
            if (st2[i] == true) {
                count++;
            }
        }

        return count;
    }
};

/**************************************************************** JAVA ****************************************************************/

// Approach : Using HashSet
// T.C      : O(n^2 + n * uniquePairsXors)
// S.C      : O(uniquePairXors + uniqueTripletXors)

class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;

        HashSet<Integer> pairXor = new HashSet<>();

        // Store all pair XORs
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor.add(nums[i] ^ nums[j]);
            }
        }

        // Find all triplet XORs
        HashSet<Integer> tripletXor = new HashSet<>();

        for (int val : pairXor) {
            for (int num : nums) {
                tripletXor.add(val ^ num);
            }
        }

        return tripletXor.size();
    }
}

// T.C      : O(n^2 + T * n)
// S.C      : O(2*T)

class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;

        int maxEle = 0;
        for (int num : nums) {
            maxEle = Math.max(maxEle, num);
        }

        int T = 1;
        while (T <= maxEle) {
            T <<= 1;
        }

        boolean[] pairXor = new boolean[T];
        boolean[] tripletXor = new boolean[T];

        // Store pair Xors
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int val = nums[i] ^ nums[j];
                pairXor[val] = true;
            }
        }

        // ompute triplet xors
        for (int i=0; i < T; i++) {
            if (pairXor[i] == true) {
                 for (int num: nums) {
                    tripletXor[i ^ num] = true;
                 }
            }
        }

        int count = 0;

        for (boolean exists : tripletXor) {
            if (exists == true) count++;
        }
        return count;
    }
}
