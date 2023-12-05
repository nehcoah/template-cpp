// 65

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<unordered_set<int>> food(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            if (x) food[j].insert(i);
        }
    }
    vector<vector<pair<int, int>>> adj(n);
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        sum += w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int res = 0;
    for (int z = 0; z < k; z++) {
        int cur = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            function<pair<int, int>(int, int)> dfs = [&](int x, int pa) -> pair<int, int> {
                int tot = -1, mx = -1;
                for (auto nxt : adj[x]) {
                    if (nxt.first == pa) continue;
                    auto res = dfs(nxt.first, x);
                    if (res.first != -1) {
                        if (tot == -1) tot = 0;
                        tot += res.first + nxt.second;
                        mx = max(mx, res.second + nxt.second);
                    }
                }
                if (food[z].count(x) && tot == -1) tot = 0, mx = 0;
                return {tot, mx};
            };
            auto ans = dfs(i, -1);
            cur = min(cur, 2 * ans.first - ans.second);
        }
        res = max(res, cur);
    }
    cout << res << endl;

    return 0;
}


