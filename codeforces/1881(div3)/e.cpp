#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> f(n + 1, -1);
    auto dfs = [&](auto self, int i) -> int {
        if (i > n) return inf;
        else if (i == n) return 0;
        if (f[i] != -1) return f[i];

        int ans = min(self(self, i + 1) + 1, self(self, a[i] + i + 1));
        return f[i] = ans;
    };
    int ans = dfs(dfs, 0);
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

