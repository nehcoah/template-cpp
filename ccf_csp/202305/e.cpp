#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string t;
    cin >> n >> t;
    m = t.size();

    auto pos = [&](char c) {
        for (int i = 0; i < t.size(); i++) if (c == t[i]) return i;
        return -1;
    };

    vector<string> s(n);
    vector<int> msk(n);
    vector<vector<array<int, 3>>> adj(26);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int mask = 0;
        for (char c : s[i]) {
            int p = pos(c);
            if (p != -1) mask |= 1 << p;
        }
        msk[i] = mask;
        adj[s[i][0] - 'a'].push_back({s[i].back() - 'a', int(s[i].size() - 1), mask});
    }

    vector<vector<vector<ll>>> dis(26, vector<vector<ll>>(26, vector<ll>(1 << m, 1e18)));
    for (int i = 0; i < 26; i++) {
        dis[i][i][(1 << m) - 1] = 0;
        priority_queue<array<ll, 3>> pq;
        pq.push({0, i, (1 << m) - 1});
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            ll d = -cur[0], u = cur[1], mask = cur[2];
            if (d > dis[i][u][mask]) continue;
            for (auto &nxt : adj[u]) {
                int v = nxt[0], len = nxt[1], cmask = nxt[2];
                int nmask = mask ^ (mask & cmask);
                if (len + dis[i][u][mask] < dis[i][v][nmask]) {
                    dis[i][v][nmask] = dis[i][u][mask] + len;
                    pq.push({-dis[i][v][nmask], v, nmask});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int start = s[i].back() - 'a', end = s[i].front() - 'a';
        ll ans = dis[start][end][0];
        for (int sub = msk[i]; sub; sub = (sub - 1) & msk[i]) {
            ans = min(ans, dis[start][end][sub]);
        }
        if (ans == ll(1e18)) cout << -1 << "\n";
        else cout << ans + s[i].size() - 1 << "\n";
    }

    return 0;
}


