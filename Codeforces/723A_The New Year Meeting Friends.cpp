// T.C : O(1)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, x2, x3;
    cin >> x1;
    cin >> x2;
    cin >> x3;
    
    int maxDist = max({x1, x2, x3});
    int minDist = min({x1, x2, x3});
    
    if (maxDist == x1 && minDist == x2) {
        cout << (x3-x2) + (x1-x3);
        
    } else if (maxDist == x1 && minDist == x3) {
        cout << (x2-x3) + (x1-x2);
        
    } else if (maxDist == x2 && minDist == x1) {
        cout << (x3-x1) + (x2-x3);
        
    } else if (maxDist == x2 && minDist == x3) {
        cout << (x1-x3) + (x2-x1);
        
    } else if (maxDist == x3 && minDist == x1) {
        cout << (x2-x1) + (x3-x2);
        
    } else if (maxDist == x3 && minDist == x2) {
        cout << (x1-x2) + (x3-x1);
        
    }
}