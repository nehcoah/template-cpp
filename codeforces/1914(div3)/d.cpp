#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> t(n, vector<int>(3));
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i][1];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i][2];
    }

    vector<int> f(1 << 3);
    for (int i = 0; i < n; i++) {
        auto tmp = f;
        for (int mask = 0; mask < 1 << 3; mask++) {
            for (int j = 0; j < 3; j++) {
                if (mask >> j & 1) tmp[mask] = max(tmp[mask], f[mask & ~(1 << j)] + t[i][j]);
            }
        }
        f.swap(tmp);
    }
    cout << f[7] << endl;
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

