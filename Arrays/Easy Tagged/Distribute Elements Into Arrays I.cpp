/*
    Company Tags        : 
    Leetcode Link       :  https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
*/


/********************************************************************* C++ ****************************************************************/

// T.C      : O(N)
// S.C      : O(N)


class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr1, arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i <= n-1; i++) {
            if (arr2.back() < arr1.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        for (int i=0; i < arr2.size(); i++) {
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};




/********************************************************************* JAVA ****************************************************************/

// T.C      : O(N)
// S.C      : O(N)

class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length;

        List<Integer> arr1 = new ArrayList<>();
        List<Integer> arr2 = new ArrayList<>();

        arr1.add(nums[0]);
        arr2.add(nums[1]);

        for (int i = 2; i <= n-1; i++) {
            if (arr2.get(arr2.size() - 1) < arr1.get(arr1.size() - 1)) {
                arr1.add(nums[i]);
            } else {
                arr2.add(nums[i]);
            }
        }

        arr1.addAll(arr2);

        int[] result = new int[arr1.size()];
        for (int i = 0; i < arr1.size(); i++) {
            result[i] = arr1.get(i);
        }
        return result;
    }
}