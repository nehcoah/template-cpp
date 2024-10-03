#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n)), h(n, vector<int>(n));
    int mg;
    cin >> mg;
    for (int i = 0; i < mg; i++) {
        int u, v; cin >> u >> v;
        u -= 1, v -= 1;
        g[u][v] = g[v][u] = 1;
    }
    int mh;
    cin >> mh;
    for (int i = 0; i < mh; i++) {
        int u, v; cin >> u >> v;
        u -= 1, v -= 1;
        h[u][v] = h[v][u] = 1;
    }
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    int ans = 1e9;
    do {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (h[i][j] != g[p[i]][p[j]]) {
                    cur += cost[i][j];
                }
            }
        }
        ans = min(ans, cur);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;

    return 0;
}

