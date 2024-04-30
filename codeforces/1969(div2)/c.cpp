//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector f(n, vector<ll>(k + 1, -1));
    auto dfs = [&](auto self, int i, int cnt) -> ll {
        if (i == n) return 0;
        if (f[i][cnt] != -1) return f[i][cnt];
        ll ans = numeric_limits<ll>::max();
        int mn = a[i];
        for (int j = 0; j <= cnt && i + j < n; j++) {
            mn = min(mn, a[i + j]);
            ans = min(ans, self(self, i + j + 1, cnt - j) + 1ll * mn * (j + 1));
        }
        return f[i][cnt] = ans;
    };
    cout << dfs(dfs, 0, k) << endl;
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
