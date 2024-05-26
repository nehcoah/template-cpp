#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    a -= 1, b -= 1;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int m = -1, ans = 0;
    queue<int> qa, qb;
    vector<int> visa(n), visb(n);
    qa.push(a), qb.push(b);
    visa[a] = 1, visb[b] = 1;
    if (a == b) m = a;
    while (m == -1) {
        for (int i = qa.size(); i > 0; i--) {
            int x = qa.front(); qa.pop();
            for (int y : adj[x]) {
                if (visa[y]) continue;
                qa.push(y); visa[y] = 1;
            }
        }
        for (int i = qb.size(); i > 0; i--) {
            int x = qb.front(); qb.pop();
            for (int y : adj[x]) {
                if (visa[y]) {
                    m = y;
                    break;
                }
                if (visb[y]) continue;
                qb.push(y); visb[y] = 1;
            }
        }
        ans += 1;
    }

    queue<int> q;
    vector<int> vis(n);
    q.push(m); vis[m] = 1;
    int d = -1;
    while (!q.empty()) {
        for (int i = q.size(); i > 0; i--) {
            int x = q.front(); q.pop();
            for (int y : adj[x]) {
                if (vis[y]) continue;
                q.push(y), vis[y] = 1;
            }
        }
        d += 1;
    }
    cout << 2 * (n - 1) - d + ans << endl;
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
