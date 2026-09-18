// T.C : O(n)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    
    cin >> s;
    
    unordered_set<char> st = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
    string res;
    
    for (char ch : s) {
        if (st.find(ch) != st.end()) { // its a vowel
            continue;
        } else {
            res.push_back('.');
            if (isupper(ch)) {
                res.push_back(tolower(ch));
            } else {
                res.push_back(ch);
            }
        }
    }
    cout << res;
}