/*
    Company Tags    :   
    LeetCode Link   :  https://leetcode.com/problems/can-place-flowers/description
*/

/**************************************************************** C++ ****************************************************************/
 
// T.C      : O(n)
// S.C      : O(1)


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int N = flowerbed.size();
        
        for (int i = 0; i < N; i++) {
            // Check if current, left, and right plots are all clear
            if (flowerbed[i] == 0 && 
               (i == 0 || flowerbed[i-1] == 0) && 
               (i == N-1 || flowerbed[i+1] == 0)) {
                
                flowerbed[i] = 1; // Plant the flower
                n--;              // Decrement remaining flowers needed
                
                if (n == 0) return true; // Early exit optimization
            }
        }
        return n == 0;
    }
};

/**************************************************************** JAVA ****************************************************************/

// T.C      : O(n)
// S.C      : O(1)

class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if (n == 0) return true;

        int N = flowerbed.length;

        for (int i = 0; i < N; i++) {

            if (flowerbed[i] == 0 && (
                i == 0 || flowerbed[i-1] == 0) && (i == N-1 || flowerbed[i+1] == 0)
            ) {
                flowerbed[i] = 1;
                n--;

                if (n == 0) return true;
            }
        }
        return n == 0;   
    }
}