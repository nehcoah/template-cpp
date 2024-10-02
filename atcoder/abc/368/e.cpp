#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, X;
    cin >> n >> m >> X;
    vector<array<int, 4>> info(m);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        a -= 1, b -= 1;
        info[i] = {a, b, s, t};
        adj[a].emplace_back(b, i);
    }

    vector<array<int, 3>> e(2 * m);
    for (int i = 0; i < m; i++) {
        e[2 * i] = {info[i][2], 1, i};
        e[2 * i + 1] = {info[i][3], 0, i};
    }
    sort(e.begin(), e.end());
    vector<ll> ans(m), tmp(n);
    ans[0] = X;
    for (auto [t, o, i] : e) {
        if (o == 1) {
            ans[i] = max(ans[i], tmp[info[i][0]] - info[i][2]);
        } else {
            tmp[info[i][1]] = max(tmp[info[i][1]], info[i][3] + ans[i]);
        }
    }
    for (int i = 1; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
    }

    return 0;
}

