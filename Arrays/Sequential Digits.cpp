/*
    Company Tags                : 
    Leetcode Link               :  https://leetcode.com/problems/sequential-digits/description/
*/


/**************************************************************** C++ ****************************************************************/

// T.C : O(36) (Total 36 sequential digits)
// S.C : O(1)  (excluding output array)

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";

        for (int len = 2; len <= 9; len++) {

            for (int start = 0; start + len <= 9; start++) {

                int num = stoi(s.substr(start, len));

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};



/**************************************************************** JAVA ****************************************************************/

// T.C : O(36) (Total 36 sequential digits)
// S.C : O(1)  (excluding output array)


class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> ans = new ArrayList<>();
        String s = "123456789";

        for (int len = 2; len <= 9; len++) {

            for (int start = 0; start + len <= 9; start++) {

                int num = Integer.parseInt(s.substring(start, start + len));

                if (num >= low && num <= high) {
                    ans.add(num);
                }
            }
        }
        return ans;
    }
}