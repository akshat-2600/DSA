// T.C : O(n)
// S.C : O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    unordered_set<char> st;
    
    for (char ch : s) {
        st.insert(ch);
    }
    
    int distinctChars = st.size();
    if (distinctChars % 2 == 0) {
        cout << "CHAT WITH HER!";
    } else {
        cout << "IGNORE HIM!";
    }
    
}