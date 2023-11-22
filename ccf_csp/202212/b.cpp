#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> p(m), t(m);
    vector<vector<int>> adj(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        p[i]--;
        if (p[i] >= 0) adj[p[i]].push_back(i);
    }
    for (int i = 0; i < m; i++) cin >> t[i];

    bool ok = true;
    vector<int> e(m), l(m);
    for (int i = 0; i < m; i++) {
        if (e[i] != 0 || p[i] != -1) continue;
        function<int(int, int)> dfs = [&](int x, int time) -> int {
            e[x] = time;
            int ans = 0;
            for (int y : adj[x]) {
                ans = max(ans, dfs(y, time + t[x]));
            }
            l[x] = n - ans - t[x] + 1;
            if (l[x] < 1) ok = false;
            return ans + t[x];
        };
        dfs(i, 1);
    }
    for (int i = 0; i < m; i++) cout << e[i] << " \n"[i == m - 1];
    if (ok) for (int i = 0; i < m; i++) cout << l[i] << " \n"[i == m - 1];

    return 0;
}


