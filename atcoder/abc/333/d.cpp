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
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (adj[0].size() == 1) {
        cout << 1 << endl;
        return 0;
    }
    auto dfs = [&](auto self, int x, int pa) -> int {
        int cnt = 1;
        for (int y : adj[x]) {
            if (y == pa) continue;
            cnt += self(self, y, x);
        }
        return cnt;
    };
    vector<int> ans;
    for (int x : adj[0]) {
        ans.push_back(dfs(dfs, x, 0));
    }
    sort(ans.begin(), ans.end());
    ans.pop_back();
    cout << accumulate(ans.begin(), ans.end(), 0) + 1 << endl;

    return 0;
}

