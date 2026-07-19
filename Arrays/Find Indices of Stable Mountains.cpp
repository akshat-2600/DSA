/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/find-indices-of-stable-mountains/
*/


/************************************************************ C++ ************************************************************/

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> result;

        for (int i = 1; i < height.size(); i++) {
            if (height[i-1] > threshold) {
                result.push_back(i);
            }
        }
        return result;
    }
};

/************************************************************ Java ************************************************************/

class Solution {
    public List<Integer> stableMountains(int[] height, int threshold) {
        List<Integer> result = new ArrayList<>();

        for (int i = 1; i < height.length; i++) {
            if (height[i-1] > threshold) {
                result.add(i);
            }
        }
        return result;
    }
}