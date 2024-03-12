#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> route(n);
    map<int, set<int>> color;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        color[c].insert(u);
        color[c].insert(v);
        route[u].insert(c);
        route[v].insert(c);
    }
    int b, e, ans = 0;
    cin >> b >> e;
    b--, e--;
    queue<int> q;
    q.push(b);
    vector<int> vis(n);
    vis[b] = true;
    while (!q.empty()) {
        queue<int> nxt;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            if (x == e) {
                cout << ans << endl;
                return;
            }
            for (int c : route[x]) {
                for (int y : color[c]) {
                    if (vis[y]) continue;
                    vis[y] = true;
                    nxt.push(y);
                }
            }
        }
        q.swap(nxt);
        ans += 1;
    }
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
