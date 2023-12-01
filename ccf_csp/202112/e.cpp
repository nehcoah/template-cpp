#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<vector<int>> adj(n + 1);
    vector<int> d(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++, d[v]++;
    }
    bool a1 = false, a2 = false;
    auto b = d;
    int c = -1;
    sort(b.begin(), b.end());
    if (n == 2 || b[1] == b[2] && b[1] == 1 && b[3] == 2 && b.back() == 2) a1 = true;
    for (int i = 0; i <= n; i++) if (d[i] == n - 1) a2 = true, c = i;

    if (n <= 5000) {
        int mx = -1, mn = numeric_limits<int>::max();
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int s, int x, int pa) {
            for (int y : adj[x]) {
                if (pa == y) continue;
                int t1 = mx, t2 = mn;
                mx = max(mx, y), mn = min(mn, y);
                if (min(s, y) - k1 <= mn && mx <= max(s, y) + k2) ans++;
                dfs(s, y, x);
                mx = t1, mn = t2;
            }
        };
        for (int i = 1; i <= n; i++) {
            dfs(i, i, -1);
        }
        cout << ans / 2 + n << "\n";
    }
    if (a1) {
        cout << (1ll + n) * n / 2 << "\n";
    }
    if (a2) {
        ll mn = min(n, c + k1), mx = max(1, c - k2);
        ll ans = n + n - 1;
        ans += (mx - 1) * (n - mx);
        for (ll i = mx; i <= mn; i++) {
            if (i == c) continue;
            ans += n - i - (i < c);
        }
        cout << ans << "\n";
    }

    return 0;
}


