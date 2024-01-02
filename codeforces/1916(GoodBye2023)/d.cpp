#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    cout << "196" << string(n - 3, '0') << endl;
    for (int i = 0; i < n / 2; i++) {
        cout << "1" << string(i, '0') << "6" << string(i, '0') << "9" << string(n - 3 - 2 * i, '0') << endl;
        cout << "9" << string(i, '0') << "6" << string(i, '0') << "1" << string(n - 3 - 2 * i, '0') << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

