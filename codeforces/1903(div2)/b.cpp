#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    vector<int> ans(n, (1 << 30) - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) ans[i] &= M[i][j];
        }
    }
    bool good = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ans[i] | ans[j]) != M[i][j]) {
                good = false;
                break;
            }
        }
    }
    if (good) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
    } else cout << "NO\n";
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


