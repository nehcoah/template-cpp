#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector dp(n, vector(3, vector<ll>(2, -1)));
    auto dfs = [&](auto self, int i, int pre, bool f) -> ll {
        if (i == n) return f ? 0 : 1e18;
        if (dp[i][pre][f] != -1) return dp[i][pre][f];
        ll ans = numeric_limits<ll>::max();
        int cur = s[i] - '0';
        if (i == 0) {
            ans = min(ans, self(self, i + 1, cur, f));
            ans = min(ans, self(self, i + 1, !cur, f) + c[i]);
        } else {
            if (!f) {
                ans = min(ans, self(self, i + 1, cur, cur == pre));
                ans = min(ans, self(self, i + 1, !cur, (!cur) == pre) + c[i]);
            } else {
                if (pre == cur) ans = min(ans, self(self, i + 1, !cur, f) + c[i]);
                else ans = min(ans, self(self, i + 1, cur, f));
            }
        }
        return dp[i][pre][f] = ans;
    };
    cout << dfs(dfs, 0, 2, false) << endl;

    return 0;
}
