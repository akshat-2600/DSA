/*
    Company Tags         :  
    LeetCode Link        :  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


/**************************************************************** C++ ****************************************************************/

// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                result.push_back(i);
                break;
            }
        }

        for (int j = n-1; j >= 0; j--) {
            if (nums[j] == target) {
                result.push_back(j);
                break;
            }
        }

        if (result.size() == 2) {
            return result;
        } else if (result.size() == 1) {
            return {result[0], result[0]};
        } 
        return {-1, -1};
    }
};


// T.C : O(log(n))
// S.C : O(1)


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        result[0] = left;
        result[1] = right;
        return result;        
    }

    int binarySearch(vector<int>& nums, int target, bool isSearchingLeft) {
        int left = 0;
        int right = nums.size() - 1;
        int idx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                idx = mid;
                if (isSearchingLeft) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return idx;
    }    
};

/**************************************************************** JAVA ****************************************************************/

// T.C : O(n)
// S.C : O(1)

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n = nums.length;
        List<Integer> result = new ArrayList<>();

        // Find the first occurrence
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                result.add(i);
                break;
            }
        }

        // Find the last occurrence
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] == target) {
                result.add(j);
                break;
            }
        }

        // Return results based on matches found
        if (result.size() == 2) {
            return new int[]{result.get(0), result.get(1)};
        } else if (result.size() == 1) {
            return new int[]{result.get(0), result.get(0)};
        }

        return new int[]{-1, -1};
    }
}


// T.C : O(log(n))
// S.C : O(1)

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = {-1, -1};
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        result[0] = left;
        result[1] = right;
        return result;        
    }

    private int binarySearch(int[] nums, int target, boolean isSearchingLeft) {
        int left = 0;
        int right = nums.length - 1;
        int idx = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                idx = mid;
                if (isSearchingLeft) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return idx;
    }

}