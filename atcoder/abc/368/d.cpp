#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        v[i] -= 1;
    }
    set<int> st{v.begin(), v.end()};

    int ans = n;
    auto dfs = [&](auto self, int x, int pa) -> bool {
        bool ok = st.contains(x);
        for (int y : adj[x]) {
            if (y == pa) continue;
            ok |= self(self, y, x);
        }
        ans -= !ok;
        return ok;
    };
    dfs(dfs, v[0], -1);
    cout << ans << endl;

    return 0;
}

