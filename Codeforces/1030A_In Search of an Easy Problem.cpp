// T.C : O(n)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    bool flag = true;
    cin >> n;
    
    while (n--) {
        int op;
        cin >> op;
        
        if (op == 1) {
            cout << "HARD" << endl;
            flag = false;
            break;
        }
    }
    if (flag == true) {
        cout << "EASY" << endl;
    }
}