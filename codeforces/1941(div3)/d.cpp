#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector dp(n, vector<int>(m + 1));
    dp[x - 1][0] = true;
    for (int i = 0; i < m; i++) {
        int r; cin >> r;
        char c; cin >> c;
        for (int j = 0; j < n; j++) {
            if (dp[j][i]) {
                if (c != '0') dp[(j - r + n) % n][i + 1] = true;
                if (c != '1') dp[(j + r) % n][i + 1] = true;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (dp[i][m]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int y : ans) cout << y + 1 << " \n"[y == ans.back()];
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
