// T.C : O(1)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    if (isupper(s[0])) {
        cout << s;
    } else {
        int ascii = s[0] - 0;
        cout << char(ascii - 32) + s.substr(1);
    }
}