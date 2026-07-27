/*
    Company Tags    :   
    LeetCode Link   :  https://leetcode.com/problems/reverse-vowels-of-a-string/description/
*/

/**************************************************************** C++ ****************************************************************/
 
// Approach : Creating new string
// T.C      : O(N)
// S.C      : O(1)

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> result;

        for (char ch: s) {
            if (vowel.find(ch) != vowel.end()) {
                result.push_back(ch);
            }
        }
        
        int idx = result.size() - 1;

        for (int i=0; i < s.length(); i++) {
            if (vowel.find(s[i]) != vowel.end()) {
                s[i] = result[idx];
                idx--;
            }
        }
        return s;
    }
};

// Approach : Inplace changes in string
// T.C      : O(N)
// S.C      : O(1)

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        vector<char> start;

        string result = "";

        for (char ch : s) {
            if (vowels.find(ch) != vowels.end()) {
                start.push_back(ch);
            }
        }

        for (char ch : s) {
            if (vowels.find(ch) != vowels.end()) {
                char vowel = start.back();
                start.pop_back();
                result += vowel;
            } else {
                result += ch;
            }
        }

        return result;
    }
};



/**************************************************************** JAVA ****************************************************************/

// Approach : Creating new string
// T.C      : O(N)
// S.C      : O(1)

class Solution {
    public String reverseVowels(String s) {
        
        HashSet<Character> vowels = new HashSet<>(Arrays.asList(
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
        ));

        ArrayList<Character> list = new ArrayList<>();

        // Store all vowels
        for (char ch : s.toCharArray()) {
            if (vowels.contains(ch)) {
                list.add(ch);
            }
        }

        char[] arr = s.toCharArray();
        int idx = list.size() - 1;

        // Replace vowels from the end
        for (int i = 0; i < arr.length; i++) {
            if (vowels.contains(arr[i])) {
                arr[i] = list.get(idx);
                idx--;
            }
        }

        return new String(arr);
    }
}

// Approach : Inplace changes in string
// T.C      : O(N)
// S.C      : O(1)

class Solution {
    public String reverseVowels(String s) {
        
        HashSet<Character> vowels = new HashSet<>(Arrays.asList(
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
        ));

        Stack<Character> stack = new Stack<>();

        // Push all vowels
        for (char ch : s.toCharArray()) {
            if (vowels.contains(ch)) {
                stack.push(ch);
            }
        }

        StringBuilder result = new StringBuilder();

        for (char ch : s.toCharArray())  {
            if (vowels.contains(ch)) {
                result.append(stack.pop());
            } else {
                result.append(ch);
            }
        }

        return result.toString();
    }
}