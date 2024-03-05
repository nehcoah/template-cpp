#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    ll T = 0;
    vector<int> w(n), p(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        T += w[i];
    }
    p[0] = -1;
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i);
    }

    vector<ll> Sum(n);
    vector<bitset<2001>> sub(n);
    auto dfs = [&](auto self, int x) -> void {
        for (auto y : adj[x]) {
            self(self, y);
            Sum[x] += Sum[y];
            sub[x] |= sub[y];
        }
        Sum[x] += w[x];
        sub[x].set(x);
    };
    dfs(dfs, 0);

    while (m--) {
        int q; cin >> q;
        q--;
        auto sum = Sum;
        auto state = sub[0];
        auto tot = T;
        auto find_query = [&]() {
            ll mn = tot;
            int id = -1;
            for (int i = 0; i < n; i++) {
                if (state.test(i) == 0) continue;
                ll t = abs(sum[i] - (tot - sum[i]));
                if (t < mn) {
                    mn = t, id = i;
                }
            }
            return id;
        };
        auto check = [&](int x, int y) {
            return sub[x].test(y);
        };
        auto get_sum = [&](int c) {
            ll t = 0;
            auto d = [&](auto self, int x) -> void {
                if (state.test(x)) t += w[x];
                for (auto y : adj[x]) {
                    self(self, y);
                }
            };
            d(d, c);
            return t;
        };

        while (true) {
            if (state.count() == 1) break;
            int i = find_query();
            if (check(i, q)) {
                tot = get_sum(i);
                state &= sub[i];
            } else {
                ll s = get_sum(i);
                tot -= s;
                for (int x = i; x != -1; x = p[x]) {
                    sum[x] -= s;
                }
                state &= ~sub[i];
            }
            cout << i + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
