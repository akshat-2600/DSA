/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/maximum-product-of-three-numbers/


/**************************************************************** C++ ****************************************************************/

/*
Approach : If array size == 3 then directly calculating the product of elements
           sorting the array
           only two possible cases

           maxLeft  = smallest * second_smallest * largest
           maxRight = largest  * second_largest  * third+largest

           return max(maxLeft, maxRight)


T.C      : O(N * log(N))
S.C      : O(1)
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3) {
            return nums[0] * nums[1] * nums[2];
        }

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n-1;

        int maxProd = 1;
        int a = nums[i];
        int b = nums[i+1];
        int e = nums[j];
        int d = nums[j-1];
        int c = nums[j-2];

        int maxLeft = a * b * e;
        int maxRight = e * d * c;

        if (maxLeft > maxRight) {
            return maxLeft;
        } else {
            return maxRight;
        }
        return 0;
    }
};


/**************************************************************** JAVA ****************************************************************/


/*
Approach : If array size == 3 then directly calculating the product of elements
           sorting the array
           only two possible cases

           maxLeft  = smallest * second_smallest * largest
           maxRight = largest  * second_largest  * third+largest

           return max(maxLeft, maxRight)


T.C      : O(N * log(N))
S.C      : O(1)
*/

class Solution {
    public int maximumProduct(int[] nums) {
        // If there are exactly 3 elements, return their product immediately
        if (nums.length == 3) {
            return nums[0] * nums[1] * nums[2];
        }
        
        int n = nums.length;
        // Sort the array in ascending order
        Arrays.sort(nums);
        
        int i = 0;
        int j = n - 1;
        
        int a = nums[i];     // Smallest element (most negative if negatives exist)
        int b = nums[i + 1]; // Second smallest element
        int e = nums[j];     // Largest element
        int d = nums[j - 1]; // Second largest element
        int c = nums[j - 2]; // Third largest element
        
        // Scenario 1: Two smallest negative numbers multiplied by the largest positive number
        int maxLeft = a * b * e;
        // Scenario 2: Three largest numbers multiplied together
        int maxRight = e * d * c;
        
        // Return the absolute maximum of the two possibilities
        if (maxLeft > maxRight) {
            return maxLeft;
        } else {
            return maxRight;
        }
    }
}

