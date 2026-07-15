/*
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
*/

/************************************************** C++ **************************************************/

// T.C : O(K + N*M)
// S.C : O(K)

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;

        for (char ch: chars) {
            mp[ch]++;
        }

        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> temp = mp;
            bool canForm = true;

            for (char ch: words[i]) {
                if (temp.find(ch) == temp.end() || temp[ch] == 0) {
                    canForm = false;
                    break;
                }
                temp[ch]--;
            }

            if (canForm) {
                count += words[i].size();
            }
        }
        return count;
    }
};

/************************************************** JAVA **************************************************/

// T.C : O(K + N*M)
// S.C : O(K)

class Solution {
    public int countCharacters(String[] words, String chars) {
        
        Map<Character, Integer> mp = new HashMap<>();

        for (char ch: chars.toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }

        int count = 0;

        for (String word : words) {
            Map<Character, Integer> temp = new HashMap<>(mp);
            boolean canForm = true;

            for (char ch: word.toCharArray()) {
                if (!temp.containsKey(ch) || temp.get(ch) == 0) {
                    canForm = false;
                    break;
                }
                temp.put(ch, temp.get(ch) - 1);
            }

            if (canForm) {
                count += word.length();
            }
        }
        return count;
    }
}