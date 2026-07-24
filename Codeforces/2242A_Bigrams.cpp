// T.C : O(n)
// S.C : O(n)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        vector<int> arr(k);

        int twice = 0;
        bool three = false;

        for (int i = 0; i < k; i++) {
            cin >> arr[i];

            if (arr[i] >= 2)
                twice++;

            if (arr[i] >= 3)
                three = true;
        }

        if (three || twice >= 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}