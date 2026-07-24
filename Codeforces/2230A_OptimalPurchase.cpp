#include <iostream>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        long long n, a, b;

        cin >> n >> a >> b;

        long long groups = n/3;
        long long rem = n%3;

        long long ans = groups * min(3*a, b) + min(rem * a, b);
    
        cout << ans << endl;
    }
    return 0;
}