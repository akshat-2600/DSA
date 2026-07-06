/*
    Company Tags                : Zoho
    Leetcode Link               : https://www.geeksforgeeks.org/problems/maximum-number-of-characters-between-any-two-same-character4552/1?_gl=1*1lfey61*_up*MQ..&gclid=Cj0KCQiA49XMBhDRARIsAOOKJHZRNAAZienXIkpogHQ2I3rSfKT8IT3jVQg1bi2cDPURBt5pGJnkMM8aAgqDEALw_wcB&gbraid=0AAAAAC9yBkBLKTbB4j8YDewdZI2chGPOg
*/


/**************************************************************** C++ ****************************************************************/

// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    int maxCharGap(string &s) {
        int n = s.length();

        int maxNum = -1;

        unordered_map<char, pair<int, int>> mp;
        // first  -> frequency
        // second -> first occurrence index

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (mp[ch].first == 0) {
                mp[ch].first = 1;
                mp[ch].second = i;
            } else {
                mp[ch].first++;
                maxNum = max(maxNum, i - mp[ch].second - 1);
            }
        }

        return maxNum;
    }
};

/**************************************************************** JAVA ****************************************************************/

// T.C : O(n)
// S.C : O(n)

class Solution {
    public int maxCharGap(String s) {
        int n = s.length();
        
        int maxNum = -1;
        
        HashMap<Character, int[]> map = new HashMap<>();
        // int[0] -> frequency
        // int[1] -> first occurrence index
        
        for (int i=0; i < n; i++) {
            
            char ch = s.charAt(i);
            
            if (!map.containsKey(ch)) {
                map.put(ch, new int[]{1, i});
            } else {
                int[] arr = map.get(ch);
                arr[0]++; // frequency
                maxNum = Math.max(maxNum, i - arr[1] - 1);
            }
        }
        
        return maxNum;
        
    }
};