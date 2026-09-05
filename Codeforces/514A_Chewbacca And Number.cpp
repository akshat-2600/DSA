// Approach : Greedy
// T.C      : O(n)
// S.C      : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    cin >> x;

    for (int i = 0; i < x.size(); i++) {
        int digit = x[i] - '0';
        int inverted = 9 - digit;

        // Don't allow the first digit to become 0
        if (i == 0 && inverted == 0)
            continue;

        // Choose the smaller digit
        if (inverted < digit)
            x[i] = char('0' + inverted);
    }

    cout << x << endl;

    return 0;
}