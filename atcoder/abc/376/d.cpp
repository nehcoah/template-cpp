#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        adj[u].push_back(v);
    }

    vector<int> t(n, -1);
    queue<int> q;
    q.push(0);
    t[0] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : adj[x]) {
            if (t[y] != -1) {
                if (y == 0) {
                    cout << t[x] + 1 << endl;
                    return 0;
                }
            } else {
                q.push(y);
                t[y] = t[x] + 1;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}

