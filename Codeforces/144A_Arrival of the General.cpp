// T.C : O(n)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int smallestIdx = INT_MAX;
    int largestIdx  = INT_MIN;
    int maxNum      = INT_MIN;
    int minNum      = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if (x > maxNum) {
            largestIdx = i;
            maxNum = x;
        }
        if (x <= minNum) {
            smallestIdx = i;
            minNum = x;
        }
    }
    int ans = largestIdx + (n-1 - smallestIdx);
    
    if (largestIdx > smallestIdx) {
        ans--;
    }
    cout << ans << endl;
}