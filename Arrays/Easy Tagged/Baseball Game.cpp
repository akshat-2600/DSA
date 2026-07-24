/*
    Company Tags         :  
    LeetCode Link        :  https://leetcode.com/problems/baseball-game/description/


/**************************************************************** C++ ****************************************************************/

// T.C : O(N)
// S.C : O(N)

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        vector<int> ans;

        for (int i = 0; i < operations.size(); i++) {
            string ch = operations[i];

            if (ch != "+" && ch != "D" && ch != "C") {
                ans.push_back(stoi(ch));
                sum += ans.back();
            
            } else if (ch == "+") {
                int n = ans.size();

                int x = ans[n - 1];
                int y = ans[n - 2];

                ans.push_back(x + y);
                sum += ans.back();
         
            } else if (ch == "D") {
                int score = 2 * ans.back();
                ans.push_back(score);
                sum += score;

            } else if (ch == "C") {
                sum -= ans.back();

                ans.pop_back();
                
            }
        }

        return sum;
    }
};

/**************************************************************** JAVA ****************************************************************/

// T.C : O(N)
// S.C : O(N)

class Solution {
    public int calPoints(String[] operations) {
        int sum = 0;

        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < operations.length; i++) {
            String ch = operations[i];

            if (!ch.equals("+") && !ch.equals("D") && !ch.equals("C")) {

                ans.add(Integer.parseInt(ch));
                sum += ans.get(ans.size() - 1);
            }
            else if (ch.equals("+")) {
                int n = ans.size();
                int x = ans.get(n - 1);
                int y = ans.get(n - 2);
                ans.add(x + y);
                sum += ans.get(ans.size() - 1);
            }
            else if (ch.equals("D")) {
                int score = 2 * ans.get(ans.size() - 1);
                ans.add(score);
                sum += score;
            }
            else if (ch.equals("C")) {
                sum -= ans.get(ans.size() - 1);
                ans.remove(ans.size() - 1);
            }
        }
        return sum;
    }
}