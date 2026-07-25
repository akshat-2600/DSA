/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/letter-combinations-of-a-phone-number/description
*/


/**************************************************************** C++ ****************************************************************/

// Approach : Nested Loops (Brute Force)
// T.C      : O(4^n * n)
// S.C      : O(1)

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        unordered_map<int, vector<string>> mp = {
            {2, {"a", "b", "c"}},
            {3, {"d", "e", "f"}},
            {4, {"g", "h", "i"}},
            {5, {"j", "k", "l"}},
            {6, {"m", "n", "o"}},
            {7, {"p", "q", "r", "s"}},
            {8, {"t", "u", "v"}},
            {9, {"w", "x", "y", "z"}}
        };
        
        int n = digits.length();

        vector<string> vec1;
        vector<string> vec2;
        vector<string> vec3;
        vector<string> vec4;

        vector<string> res;

        if (n == 1) {
            vector<string> vec1 = mp[digits[0] - '0'];

            return vec1;
        }
        else if (n == 2) {
            vector<string> vec1 = mp[digits[0] - '0'];
            vector<string> vec2 = mp[digits[1] - '0'];

            for (int i = 0; i < vec1.size(); i++) {
                string st = vec1[i];

                for (int j = 0; j < vec2.size(); j++) {
                    res.push_back(st + vec2[j]);
                }
            }

            return res;
        }
        else if (n == 3) {
            vector<string> vec1 = mp[digits[0] - '0'];
            vector<string> vec2 = mp[digits[1] - '0'];
            vector<string> vec3 = mp[digits[2] - '0'];

            for (int i = 0; i < vec1.size(); i++) {
                string a = vec1[i];

                for (int j = 0; j < vec2.size(); j++) {
                    string b = vec2[j];
                    
                    for (int k = 0; k < vec3.size(); k++) {
                        res.push_back(a + b + vec3[k]);
                    }
                }
            }
            return res;
        }
        else if (n == 4) {
            vector<string> vec1 = mp[digits[0] - '0'];
            vector<string> vec2 = mp[digits[1] - '0'];
            vector<string> vec3 = mp[digits[2] - '0'];
            vector<string> vec4 = mp[digits[3] - '0'];

            for (int i = 0; i < vec1.size(); i++) {
                string a = vec1[i];

                for (int j = 0; j < vec2.size(); j++) {
                    string b = vec2[j];
                    
                    for (int k = 0; k < vec3.size(); k++) {
                        string c = vec3[k];

                        for (int l = 0; l < vec4.size(); l++) {
                            res.push_back(a + b + c + vec4[l]);
                        }
                    }
                }
            }
            return res;
        } 
        return {};
    }
};


// Approach : Backtracking
// T.C      : O(4^n * n)
// S.C      : O(1)

class Solution {
public:
    vector<string> ans;

    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(int idx, string &curr, string &digits) {
        //Base case
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx]];

        for (char ch : letters) {
            curr.push_back(ch);
            solve(idx+1, curr, digits);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        if (digits.empty()) {
            return {};
        }

        string curr = "";
        solve(0, curr, digits);

        return ans;
    }
};

/**************************************************************** JAVA ****************************************************************/

// Approach : Nested Loops (Brute Force)
// T.C      : O(4^n * n)
// S.C      : O(1)

class Solution {
    public List<String> letterCombinations(String digits) {
        
        HashMap<Integer, List<String>> mp = new HashMap<>();

        mp.put(2, Arrays.asList("a", "b", "c"));
        mp.put(3, Arrays.asList("d", "e", "f"));
        mp.put(4, Arrays.asList("g", "h", "i"));
        mp.put(5, Arrays.asList("j", "k", "l"));
        mp.put(6, Arrays.asList("m", "n", "o"));
        mp.put(7, Arrays.asList("p", "q", "r", "s"));
        mp.put(8, Arrays.asList("t", "u", "v"));
        mp.put(9, Arrays.asList("w", "x", "y", "z"));

        int n = digits.length();

        List<String> res = new ArrayList<>();

        if (n == 0) {
            return res;
        }

        if (n == 1) {
            return mp.get(digits.charAt(0) - '0');
        }
        else if (n == 2) {

            List<String> vec1 = mp.get(digits.charAt(0) - '0');
            List<String> vec2 = mp.get(digits.charAt(1) - '0');

            for (int i = 0; i < vec1.size(); i++) {
                String a = vec1.get(i);

                for (int j = 0; j < vec2.size(); j++) {
                    res.add(a + vec2.get(j));
                }
            }

            return res;
        }

        else if (n == 3) {

            List<String> vec1 = mp.get(digits.charAt(0) - '0');
            List<String> vec2 = mp.get(digits.charAt(1) - '0');
            List<String> vec3 = mp.get(digits.charAt(2) - '0');

            for (int i = 0; i < vec1.size(); i++) {

                String a = vec1.get(i);

                for (int j = 0; j < vec2.size(); j++) {

                    String b = vec2.get(j);

                    for (int k = 0; k < vec3.size(); k++) {
                        res.add(a + b + vec3.get(k));
                    }
                }
            }

            return res;
        }

        else if (n == 4) {

            List<String> vec1 = mp.get(digits.charAt(0) - '0');
            List<String> vec2 = mp.get(digits.charAt(1) - '0');
            List<String> vec3 = mp.get(digits.charAt(2) - '0');
            List<String> vec4 = mp.get(digits.charAt(3) - '0');

            for (int i = 0; i < vec1.size(); i++) {

                String a = vec1.get(i);

                for (int j = 0; j < vec2.size(); j++) {

                    String b = vec2.get(j);

                    for (int k = 0; k < vec3.size(); k++) {

                        String c = vec3.get(k);

                        for (int l = 0; l < vec4.size(); l++) {
                            res.add(a + b + c + vec4.get(l));
                        }
                    }
                }
            }

            return res;
        }

        return new ArrayList<>();
    }
}


// Approach : Backtracking
// T.C      : O(4^n * n)
// S.C      : O(1)

class Solution {

    List<String> ans = new ArrayList<>();

    HashMap<Character, String> mp = new HashMap<>();

    public Solution() {
        mp.put('2', "abc");
        mp.put('3', "def");
        mp.put('4', "ghi");
        mp.put('5', "jkl");
        mp.put('6', "mno");
        mp.put('7', "pqrs");
        mp.put('8', "tuv");
        mp.put('9', "wxyz");
    }

    private void solve(int idx, StringBuilder curr, String digits) {
        // Base case
        if (idx == digits.length()) {
            ans.add(curr.toString());
            return;
        }

        String letters = mp.get(digits.charAt(idx));

        for (char ch : letters.toCharArray()) {
            curr.append(ch);
            solve(idx+1, curr, digits);
            curr.deleteCharAt(curr.length() - 1);
        }
    }

    public List<String> letterCombinations(String digits) {

        if (digits.length() == 0) {
            return new ArrayList<>();
        }

        solve(0, new StringBuilder(), digits);

        return ans;
    }
}