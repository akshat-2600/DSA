// T.C : O(1)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, w;
    
    cin >> k >> n >> w;
    
    int totalBill = k * (w * (w+1)) / 2;
    int reqMoney  = totalBill - n < 0 ? 0 : totalBill - n;
    cout << reqMoney;
}