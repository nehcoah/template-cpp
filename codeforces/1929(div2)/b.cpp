#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    int tot = 4 * n - 2;
    if (k <= tot - 2) cout << (k + 1) / 2 << endl;
    else cout << (tot - 2) / 2 + k - (tot - 2) << endl;
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

