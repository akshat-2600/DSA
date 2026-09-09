// T.C : O(n)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int maxCapacity = 0;
    
    int totalPeopleInside = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        
        totalPeopleInside -= a;
        totalPeopleInside += b;
        
        maxCapacity = max(maxCapacity, totalPeopleInside);
    }
    cout << maxCapacity;
}