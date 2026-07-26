/*
    Company Tags    :   
    LeetCode Link   :  https://leetcode.com/problems/generate-parentheses/description/
*/

/**************************************************************** C++ ****************************************************************/

// Approach 1 : Brute Force with Validation 
// T.C      : O(2 ^ N * N)
// S.C      : O(N)

class Solution {
public:
    vector<string> result;

    bool isValid(string& curr) {
        int sum = 0;
        for (char &ch : curr) {
            if (ch == '(') sum++;
            else sum--;

            if (sum < 0) {
                return false;
            }
        }
        return sum == 0;
    }

    void solve(string& curr, int n) {
        if (curr.length() == 2*n) {
            if (isValid(curr)) {
                result.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(curr, n);

        curr.pop_back();

        curr.push_back(')');
        solve(curr, n);

        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        // Backtracking 
        // Do -> Explore -> Undo
        string curr = "";

        solve(curr, n);
        
        return result;
    }
};

// Approach 1 : Optimized Backtracking


class Solution {
public:
    vector<string> result;

    void solve(string& curr, int n, int open, int close) {
        if (curr.length() == 2*n) {
            result.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            solve(curr, n, open+1, close);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            solve(curr, n, open, close+1);
            curr.pop_back();
        } 
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";

        int open = 0;
        int close = 0;

        solve(curr, n, open, close);

        return result;
    }
};

/**************************************************************** JAVA ****************************************************************/

// Approach 1 : Brute Force with Validation 
// T.C      : O(2 ^ N * N)
// S.C      : O(N)

class Solution {
    List<String> result = new ArrayList<>();

    boolean isValid(StringBuilder curr) {
        int sum = 0;
        for (int i = 0; i < curr.length(); i++) {
            char ch = curr.charAt(i);

            if (ch == '(') sum++;
            else sum--;

            if (sum < 0) return false;
        }
        return sum == 0;
    }

    void solve(StringBuilder curr, int n) {
        if (curr.length() == 2*n) {
            if (isValid(curr)) {
                result.add(curr.toString());
            }
            return;
        }

        curr.append('(');
        solve(curr, n);
        curr.deleteCharAt(curr.length() - 1);

        curr.append(')');
        solve(curr, n);
        curr.deleteCharAt(curr.length() - 1);
    }

    public List<String> generateParenthesis(int n) {
        
        result.clear();
        StringBuilder curr = new StringBuilder();

        solve(curr, n);
        return result;
    }
}

// Approach 1 : Optimized Backtracking 


class Solution {
    List<String> result = new ArrayList<>();

    void solve(StringBuilder curr, int n, int open, int close) {
        if (curr.length() == 2*n) {
            result.add(curr.toString());
            return;
        }

        if (open < n) {
            curr.append('(');
            solve(curr, n, open+1, close);
            curr.deleteCharAt(curr.length() - 1);
        }

        if (close < open) {
            curr.append(')');
            solve(curr, n, open, close+1);
            curr.deleteCharAt(curr.length()-1);
        }
    }

    public List<String> generateParenthesis(int n) {
        result.clear();

        StringBuilder curr = new StringBuilder();
        solve(curr, n, 0, 0);

        return result;
    }
}