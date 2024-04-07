#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<ll> cost(n);
    vector<ll> ans(n);
    auto dfs = [&](auto self, int x, int pa, int d) -> ll {
        ans[0] += 1ll * c[x] * d;
        cost[x] = c[x];
        for (int y : adj[x]) {
            if (y == pa) continue;
            cost[x] += self(self, y, x, d + 1);
        }
        return cost[x];
    };
    dfs(dfs, 0, -1, 0);

    ll sum = accumulate(c.begin(), c.end(), 0ll);
    auto reroot = [&](auto self, int x, int pa) -> void {
        for (int y : adj[x]) {
            if (y == pa) continue;
            ans[y] = ans[x] - cost[y] + sum - cost[y];
            self(self, y, x);
        }
    };
    reroot(reroot, 0, -1);
    cout << *min_element(ans.begin(), ans.end()) << endl;

    return 0;
}
