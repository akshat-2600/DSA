/*
    Company Tags       : 
    LeetCode Link      :  https://leetcode.com/problems/isomorphic-strings/description/


/************************************************************ C++ ************************************************************/

// Approach : Using Unodered map one for mapping s -> t and other to stored characters already compared for t
// T.C      : O(n)
// S.C      : O(2*n)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, bool> vis; 

        for (int i = 0; i < s.size(); i++) {

            if (!vis[t[i]] && mp.find(s[i]) == mp.end()) {
                mp[s[i]] = t[i];
                vis[t[i]] = true;
            } else {
                if (mp[s[i]] == t[i]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};





/************************************************************ Java ************************************************************/

// Approach : Using Unodered map one for mapping s -> t and other to stored characters already compared for t
// T.C      : O(n)
// S.C      : O(2*n)

class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        HashMap<Character, Character> mp = new HashMap<>();
        HashMap<Character, Boolean> vis = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {

            char sChar = s.charAt(i);
            char tChar = t.charAt(i);

            if (!vis.getOrDefault(tChar, false) && !mp.containsKey(sChar)) {
                mp.put(sChar, tChar);
                vis.put(tChar, true);
            } else {
                if (mp.getOrDefault(sChar, '#') == tChar) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}