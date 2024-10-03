#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector f(n, vector<ll>(2, -1));
    auto dfs = [&](auto self, int i, int p) {
        if (i == n) return 0ll;
        if (f[i][p] != -1) return f[i][p];
        ll ans = 0;
        ans = max(ans, self(self, i + 1, p));
        ans = max(ans, self(self, i + 1, !p) + a[i] * (p ? 1 : 2));
        return f[i][p] = ans;
    };
    cout << dfs(dfs, 0, true) << endl;

    return 0;
}

