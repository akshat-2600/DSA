// T.C : O(inp)
// S.C : O(1)

#include <iostream>
using namespace std;
 
int main() {
    int inp;
    cin >> inp;
    
    int x = 0;
    while (inp--) {
        string s;
        cin >> s;
        int n = s.length();
        
        if (s[0] == '+' || s[n-1] == '+') {
            x += 1;
        } else if (s[0] == '-' || s[n-1] == '-') {
            x -= 1;
        }
    }
    cout << x;
}

