// T.C : O(log10(n))
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long temp  = n;
    int count = 0;
    
    while (temp != 0) {
        int dig = temp % 10;
        cout << dig << endl;
        if (dig == 7 || dig == 4) {
            count++;
        }
        temp /= 10;
    }
    if (count == 4 || count == 7) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}