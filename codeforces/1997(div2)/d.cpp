#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        v[i] -= 1;
    }

    vector<vector<ll>> adj(n);
    for (int i = 1; i < n; i++) {
        adj[v[i]].push_back(i);
        adj[i].push_back(v[i]);
    }

    auto dfs = [&](auto self, int x, int pa) -> ll {
        vector<ll> cur;
        for (ll y : adj[x]) {
            if (y == pa) continue;
            cur.push_back(self(self, y, x));
        }
        if (cur.empty()) return a[x];
        ll mn = *min_element(cur.begin(), cur.end());
        if (x == 0) return mn + a[x];
        else return a[x] > mn ? mn : (a[x] + mn) / 2;
    };

    cout << dfs(dfs, 0, -1) << endl;
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

