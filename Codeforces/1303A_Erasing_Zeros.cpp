#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        bool seen1 = false;
        int count = 0;
        
        int first_1 = s.find('1');
        int last_1  = s.rfind('1');

        if (first_1 == string::npos) {
            cout << 0 << endl;
            continue;
        }

        int zeros_to_erase = 0;
        for (int i = first_1; i <= last_1; i++) {
            if (s[i] == '0') {
                zeros_to_erase++;
            }
        }
        cout << zeros_to_erase << endl;
    }
}