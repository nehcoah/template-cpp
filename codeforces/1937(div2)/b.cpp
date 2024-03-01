#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    set<pair<int, int>> q;
    q.emplace(0, 0);
    string ans = string(1, s[0][0]);
    vector dp(2, vector<int>(n));
    dp[0][0] = 1;
    while (true) {
        set<pair<int, int>> tmp;
        int mn = 2;
        for (auto [x, y] : q) {
            if (y < n - 1) mn = min(mn, s[x][y + 1] - '0');
            if (x == 0) mn = min(mn, s[x + 1][y] - '0');
        }
        for (auto [x, y] : q) {
            if (y < n - 1 && s[x][y + 1] - '0' == mn) {
                tmp.emplace(x, y + 1);
                dp[x][y + 1] += dp[x][y];
            }
            if (x == 0 && s[x + 1][y] - '0' == mn) {
                tmp.emplace(x + 1, y);
                dp[x + 1][y] += dp[x][y];
            }
        }
        if (mn == 2) break;
        ans += string(1, char(mn + '0'));
        q.swap(tmp);
    }
    cout << ans << "\n";
    cout << dp[1][n - 1] << "\n";
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
