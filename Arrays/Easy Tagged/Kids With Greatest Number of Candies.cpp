/*
    Company Tags    :   
    LeetCode Link   :  https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description
*/

/**************************************************************** C++ ****************************************************************/
 
// T.C      : O(n)
// S.C      : O(1)


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> result;

        for (int candy : candies) {
            if (candy + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};



/**************************************************************** JAVA ****************************************************************/

// T.C      : O(n)
// S.C      : O(1)

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        
        List<Boolean> result = new ArrayList<>();

        int maxCandies = 0;

        for (int candy : candies) {
            maxCandies = Math.max(maxCandies, candy);
        }

        for (int candy : candies) {
            if (candy + extraCandies >= maxCandies) {
                result.add(true);
            } else {
                result.add(false);
            }
        }

        return result;
    }
}