/*
    Company Tags       : 
    LeetCode Link      :  https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/


/************************************************************ C++ ************************************************************/

// Approach : Sorting the array and then calculating the product
// T.C      : O(n * log(n))
// S.C      : O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        return (nums[0] - 1) * (nums[1] - 1);
    }
};


// Approach : Calculating maximum product by iterating over array
// T.C      : O(n)
// S.C      : O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int maxProd = -1;
        int maxNum = nums[0];

        for (int i = 1; i < n; i++) {
            int prod = (nums[i] - 1) * (maxNum - 1);

            maxProd = max(prod, maxProd);
            maxNum = max(maxNum, nums[i]);
        }

        return maxProd;
    }
};


// Approach : Finding largest and second largest by iterating and then calculating the product
// T.C      : O(n)
// T.C      : O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int largest = 0;
        int second_largest = 0;

        for (int num : nums) {
            if (num > largest) {
                second_largest = largest;
                largest = num;
            } else {
                second_largest = max(second_largest, num);   
            }
        }
        return (largest - 1) * (second_largest - 1);
    }
};

/************************************************************ Java ************************************************************/

// Approach : Sorting the array and then calculating the product
// T.C      : O(n * log(n))
// S.C      : O(1)

class Solution {
    public int maxProduct(int[] nums) {
        
        Arrays.sort(nums);

        int n = nums.length;

        return (nums[n-1] - 1) * (nums[n-2] - 1);
    }
}

// Approach : Calculating maximum product by iterating over array
// T.C      : O(n)
// S.C      : O(1)


class Solution {
    public int maxProduct(int[] nums) {
        
        int n = nums.length;

        int maxProd = -1;
        int maxNum = nums[0];

        for (int i = 1; i < n; i++) {
            int prod = (nums[i] - 1) * (maxNum - 1);

            maxProd = Math.max(maxProd, prod);
            maxNum = Math.max(maxNum, nums[i]);
        }

        return maxProd;
    }
}

// Approach : Finding largest and second largest by iterating and then calculating the product
// T.C      : O(n)
// T.C      : O(1)

class Solution {
    public int maxProduct(int[] nums) {
        
        int largest = 0;
        int second_largest = 0;

        for (int num : nums) {
            if (num > largest) {
                second_largest = largest;
                largest = num;
            } else {
                second_largest = Math.max(num, second_largest);
            }
        }

        return (largest - 1) * (second_largest - 1);
    }
}