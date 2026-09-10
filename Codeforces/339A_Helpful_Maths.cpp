// T.C : O(n)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    if (s.length() == 1) {
        cout << s;
        return 0;
    } 
    
    vector<int> vec(3, 0);
    
    for (int i = 0; i < s.length(); i += 2) {
        if (s[i] == '1') {
            vec[0]++;
        } else if (s[i] == '2') {
            vec[1]++;
        } else {
            vec[2]++;
        }
    }
    
    int idx = 0;
    
    for (int i = 0; i < 3; i++) {
        char ele;
        if (i == 0) {
            ele = '1';
        } else if (i == 1) {
            ele = '2';
        } else {
            ele = '3';
        }
        for (int j = 0; j < vec[i]; j++) {
            s[idx] = ele;
            idx += 2;
        }
    }
    cout << s;
}