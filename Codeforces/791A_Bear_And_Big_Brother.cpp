#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    
    cin >> a >> b;
    
    int years = 0;
    
    while (true) {
        if (a > b) {
            cout << years;
            break;
        }
        a *= 3;
        b *= 2;
        years++;
    }
}