/*
    Company Tags   : 
    LeetCode Link  :  https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/

/************************************************************ C++ **************************************************************/

// Appraoch : HashMap + Array List  Sorting
// T.C      : O(n + k * log(k))
// S.C      : O(k)
// where k is no. of distinct elements

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;

        for (char ch : word) {
            mp[ch]++;
        }

        vector<int> ans;
        for (auto &[c, f] : mp) {
            ans.push_back(f);
        } 

        sort(ans.begin(), ans.end(), greater<int>());

        int idx;

        for (int i = 0; i < ans.size(); i++) {
            if (i % 8 == 0) {
                idx++;
            }
            ans[i] = ans[i] * idx;
        }

        int pushes = 0;

        for (int i = 0; i < ans.size(); i++) {
            pushes += ans[i];
        }
        return pushes;

    }
};


// Appraoch : HashMap + Prefix Sum
// T.C      : O(n + k * log(k))
// S.C      : O(k)

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;

        for (char ch : word) {
            mp[ch]++;
        }

        vector<int> ans;
        for (auto &[c, f] : mp) {
            ans.push_back(f);
        } 

        sort(ans.begin(), ans.end(), greater<int>());

        int idx = 0;
        vector<int> prefix(ans.size());

        for (int i = 0; i < ans.size(); i++) {
            if (i % 8 == 0) {
                idx++;
            }

            if (i > 0) {
                prefix[i] = prefix[i-1] + (ans[i] * idx);
            } else {
                prefix[i] = ans[i] * idx;
            }
        }
        return prefix[ans.size() - 1];
    }
};

// Appraoch : Frequency Array (Best Approach)
// T.C      : O(n + 26 * log(26))  => O(n)
// S.C      : O(1)


class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);

        for (char ch : word) {
            mp[ch - 'a']++;
        }

        sort(mp.begin(), mp.end(), greater<int>());

        int idx = 0;
        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (i % 8 == 0) {
                idx++;
            }
            if (i > 0) {
                ans += mp[i] * idx;
            } else {
                ans += mp[i] * idx;
            }
        }
        return ans;
    }
};


/************************************************************ Java ************************************************************/


// Appraoch : HashMap + Array List  Sorting
// T.C      : O(n + k * log(k))
// S.C      : O(k)
//  where k is no. of distinct elements


class Solution {
    public int minimumPushes(String word) {
        HashMap<Character, Integer> map = new HashMap<>();

        for (char ch : word.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }

        List<Integer> freq = new ArrayList<>();

        for (int val : map.values()) {
            freq.add(val);
        }

        freq.sort(Collections.reverseOrder());

        int idx = 0;
        int pushes = 0;

        for (int i = 0; i < freq.size(); i++) {
            if (i % 8 == 0) {
                idx++;
            }
            pushes += freq.get(i) * idx;
        }

        return pushes;
    }
}


// Appraoch : HashMap + Prefix Sum
// T.C      : O(n + k * log(k))
// S.C      : O(k)


class Solution {
    public int minimumPushes(String word) {
        HashMap<Character, Integer> map = new HashMap<>();

        for (char ch : word.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }

        List<Integer> freq = new ArrayList<>();

        for (int val : map.values()) {
            freq.add(val);
        }

        freq.sort(Collections.reverseOrder());

        int[] prefix = new int[freq.size()];
        int idx = 0;

        for (int i = 0; i < freq.size(); i++) {
            if (i % 8 == 0) {
                idx++;
            }

            int cost = freq.get(i) * idx;

            if (i == 0) {
                prefix[i] = cost;
            } else {
                prefix[i] = prefix[i - 1] + cost;
            }
        }

        return prefix[freq.size() - 1];
    }
}

// Appraoch : Frequency Array (Best Approach)
// T.C      : O(n + 26 * log(26))  => O(n)
// S.C      : O(1)


class Solution {
    public int minimumPushes(String word) {
        int[] freq = new int[26];

        for (char ch : word.toCharArray()) {
            freq[ch - 'a']++;
        }

        Integer[] arr = new Integer[26];
        for (int i = 0; i < 26; i++) {
            arr[i] = freq[i];
        }

        Arrays.sort(arr, Collections.reverseOrder());

        int idx = 0;
        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (i % 8 == 0) {
                idx++;
            }
            ans += arr[i] * idx;
        }

        return ans;
    }
}

