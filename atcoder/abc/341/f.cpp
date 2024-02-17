#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<ll> w(n);
    vector<ll> a(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> f(n), idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return w[i] < w[j];
    });
    for (ll i : idx) {
        vector<ll> s, t;
        for (int x : adj[i]) {
            if (w[x] < w[i]) {
                s.push_back(w[x]);
                t.push_back(f[x]);
            }
        }
        if (s.empty()) f[i] = 1;
        else {
            vector<ll> dp(w[i]);
            for (int j = 0; j < s.size(); j++) {
                for (ll x = w[i] - 1; x - s[j] >= 0; x--) {
                    dp[x] = max(dp[x], dp[x - s[j]] + t[j]);
                }
            }
            f[i] = dp.back() + 1;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * f[i];
    }
    cout << ans << endl;

    return 0;
}

