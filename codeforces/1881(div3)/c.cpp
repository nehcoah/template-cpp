#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int cur = s[i][j] + s[j][n - 1 - i] + s[n - 1 - j][i] + s[n - 1 - i][n - 1 - j];
            int mx = max({s[i][j], s[j][n - 1 - i], s[n - 1 - j][i], s[n - 1 - i][n - 1 - j]});
            ans += mx * 4 - cur;
        }
    }
    cout << ans << endl;
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

