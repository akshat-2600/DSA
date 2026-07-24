#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);

        for (int i=0; i < n; i++) cin >> a[i];
        for (int i=0; i < n; i++) cin >> b[i];

        long long sumMax = 0;
        long long bestMin = 0;

        for (int i=0; i < n; i++) {
            sumMax += max(a[i], b[i]);
            bestMin = max(bestMin, min(a[i], b[i]));
        }

        cout << sumMax + bestMin << endl;
    }
    return 0;
}

/*
4
a = 2 3 6 7
b = 1 4 5 8

sumMax = 2
bestMin = 1

sumMax = 6
bestMin = 3

sumMax = 12
bestMin = 5

sumMax = 18
bestMin = 7

*/