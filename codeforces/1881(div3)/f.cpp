#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> mark(n, false);
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        mark[x - 1] = true;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dis(n, -1);
    auto bfs = [&](int t) {
        dis.assign(n, -1);
        queue<int> q;
        q.push(t);
        dis[t] = 0;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int y : adj[x]) {
                if (dis[y] == -1) {
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (mark[i] && (ans == -1 || dis[i] > dis[ans])) ans = i;
        }
        return ans;
    };

    int a = bfs(bfs(0));
    auto cur = dis;
    bfs(a);
    int ans = 1e6 + 1;

    for (int i = 0; i < n; i++) {
        ans = min(ans, max(dis[i], cur[i]));
    }
    cout << ans << endl;
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

