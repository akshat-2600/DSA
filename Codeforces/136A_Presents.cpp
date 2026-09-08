// T.C : O(n)
// S.C : O(2*n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> vec(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }
    
    vector<int> ans(n+1);
    for (int i = 1; i <= n; i++) {
        ans[vec[i]] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

// fourth number ke friend ne third wale ko gift diya hain