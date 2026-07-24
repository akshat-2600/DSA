/*
    Company Tags                :  
    GeeksForGeeks Link          :  https://leetcode.com/problems/jewels-and-stones/description/



/**************************************************************** C++ ****************************************************************/

// T.C : O(n)
// S.C    : O(n) 

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_set<char> st;

        for (char jewel : jewels) {
            st.insert(jewel);
        }
        
        int count = 0;
        for (char stone : stones) {
            if (st.find(stone) != st.end()) {
                count++;
            }
        }
        return count;
    }
};


/**************************************************************** JAVA ****************************************************************/

// T.C : O(n)
// S.C    : O(n) 

class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Set<Character> jewelSet = new HashSet<>();

        for (int i=0; i < jewels.length(); i++) {
            jewelSet.add(jewels.charAt(i));
        }

        int count = 0;
        for (int i = 0; i < stones.length(); i++) {
            if (jewelSet.contains(stones.charAt(i))) {
                count++;
            }
        }

        return count;
    }
}
