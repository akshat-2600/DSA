/*  
    Company Tags    : 
    Leetcode Link   :  https://leetcode.com/problems/construct-uniform-parity-array-i/description/
*/

/****************************************************************** C++ ****************************************************/


//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums21(n, 0); //odd
        vector<int> nums22(n, 1); //even
        
        for (int i=0; i < n; i++) {
            int num = nums[i];
            
            if (num % 2 == 0) { //even
                nums22[i] = num;
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        int a = nums[i]-nums[j];
                        if (a%2 != 0) {
                            nums21[i] = a;
                        }
                    }
                }
            } else {  // odd
                nums21[i] = num;
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        int a = nums[i]-nums[j];
                        if (a%2 == 0) {
                            nums22[i] = a;
                        }
                    }
                }
            }
        }
        
        bool flag1 = true;
        bool flag2 = true;
        
        for (int i=0; i < n; i++) {
            if (nums21[i] == 0) {
                flag1 = false;
            }
            if (nums22[i] == 1) {
                flag2 = false;
            }
            
            if (!flag1 && !flag2) {
                return false;
            }
        }
        return true;
    }
};


// Approach 2: 
// T.C : O(1)
// S.C : O(1)

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;

        /*
            if all odd -> true
            if all even -> true
            if even-odd mix  -> true 
            because an even number can be converted to odd by subtracking from a odd number 
            because parity changes when we subtract from a ODD NUMBER
        */
    }
};