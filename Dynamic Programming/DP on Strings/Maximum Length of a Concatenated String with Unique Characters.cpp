/*
    Company Tags   :  
    LeetCode Link  :  https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/

    
/************************************************************ C++ ************************************************************/

// Approach : Simple Recursion
// T.C      : O(2^N * 26)
// S.C      : O(N) (recursion stack)

class Solution {
public:
    bool hasDuplicate(string& s1, string& s2) {
        int arr[26] = {0};

        // Check all this : {"aa", "bb"}
        for (char &ch : s1) {
            if (arr[ch - 'a'] > 0) {
                return true;
            }
            arr[ch - 'a']++;
        }

        for (char &ch : s2) {
            if (arr[ch - 'a'] > 0) {
                return true;
            }
        }
        return false;
    }

    int solve(int i, vector<string>& arr, string temp, int n) {
        if (i >= n) {
            return temp.length();
        }

        int include = 0;
        int exclude = 0;

        if (hasDuplicate(arr[i], temp)) {
            exclude = solve(i+1, arr, temp, n);
        } else {
            include = solve(i+1, arr, temp + arr[i], n);
            exclude = solve(i+1, arr, temp, n);
        }
        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        
        string temp = "";

        int n = arr.size();

        return solve(0, arr, temp, n);
    }
};

// Approach : Memoization (HashMap)
// T.C      : O(N^2 * 26)
// S.C      : O(N) (recursion stack)

class Solution {
public:
    unordered_map<string, int> mp;

    bool hasDuplicate(string& s1, string& s2) {
        int arr[26] = {0};

        // Check all this : {"aa", "bb"}
        for (char &ch : s1) {
            if (arr[ch - 'a'] > 0) {
                return true;
            }
            arr[ch - 'a']++;
        }

        for (char &ch : s2) {
            if (arr[ch - 'a'] > 0) {
                return true;
            }
        }
        return false;
    }

    int solve(int i, vector<string>& arr, string temp, int n) {
        if (i >= n) {
            return temp.length();
        }

        if (mp.find(temp) != mp.end()) {
            return mp[temp];
        }
 
        int include = 0;
        int exclude = 0;

        if (hasDuplicate(arr[i], temp)) {
            exclude = solve(i+1, arr, temp, n);
        } else {
            include = solve(i+1, arr, temp + arr[i], n);
            exclude = solve(i+1, arr, temp, n);
        }
        return mp[temp] = max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        
        string temp = "";
        mp.clear();

        int n = arr.size();

        return solve(0, arr, temp, n);
    }
};


/************************************************************ Java ************************************************************/

// Approach : Simple Recursion
// T.C      : O(2^N * 26)
// S.C      : O(N) (recursion stack)

class Solution {

    private boolean hasDuplicate(String s1, String s2) {
        int[] freq = new int[26];

        for (char ch : s1.toCharArray()) {
            if (freq[ch - 'a'] > 0) {
                return true;
            }
            freq[ch - 'a']++;
        }

        for (char ch : s2.toCharArray()) {
            if (freq[ch - 'a'] > 0) {
                return true;
            }
        }
        return false;
    }

    private int solve(int i, String[] arr, String temp, int n) {
        if (i >= n) {
            return temp.length();
        }

        int include = 0;
        int exclude;

        if (hasDuplicate(arr[i], temp)) {
            exclude = solve(i+1, arr, temp, n);
        } else {
            include = solve(i+1, arr, temp + arr[i], n);
            exclude = solve(i+1, arr, temp, n);
        }

        return Math.max(include, exclude);
    }

    public int maxLength(List<String> arr) {
        
        String[] strs = arr.toArray(new String[0]);
        return solve(0, strs, "", strs.length);
    }
}


class Solution {

    private HashMap<String, Integer> memo = new HashMap<>();

    private boolean hasDuplicate(String s1, String s2) {
        int[] freq = new int[26];

        for (char ch : s1.toCharArray()) {
            if (freq[ch - 'a'] > 0) {
                return true;
            }
            freq[ch - 'a']++;
        }

        for (char ch : s2.toCharArray()) {
            if (freq[ch - 'a'] > 0) {
                return true;
            }
        }
        return false;
    }

    private int solve(int i, String[] arr, String temp, int n) {
        if (i >= n) {
            return temp.length();
        }

        if (memo.containsKey(temp)) {
            return memo.get(temp);
        }

        int include = 0;
        int exclude;

        if (hasDuplicate(arr[i], temp)) {
            exclude = solve(i+1, arr, temp, n);
        } else {
            include = solve(i+1, arr, temp + arr[i], n);
            exclude = solve(i+1, arr, temp, n);
        }

        int ans = Math.max(include, exclude);
        memo.put(temp, ans);

        return ans;
    }

    public int maxLength(List<String> arr) {
        memo.clear();
        
        String[] strs = arr.toArray(new String[0]);
        return solve(0, strs, "", strs.length);
    }
}