#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= 1;
    }
    vector<vector<int>> nadj(n);
    for (int i = 0; i < n; i++) {
        nadj[a[i]].push_back(i);
    }

    ll ans = 0;
    vector<int> vis(n);
    unordered_set<int> circle;

    auto dfs = [&](auto self, int x, int cnt) -> void {
        vis[x] = 1;
        if (!circle.contains(x)) ans += cnt - 1 + circle.size();
        for (int y : nadj[x]) {
            if (circle.contains(y)) continue;
            self(self, y, cnt + 1);
        }
    };

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        unordered_map<int, int> t;
        circle.clear();
        t[i] = 0;
        int p = i;
        do {
            t[a[p]] = t[p] + 1;
            p = a[p];
        } while (p != i && !t.contains(a[p]));
        p = a[p];
        circle.insert(p);
        for (int y = a[p]; y != p; y = a[y]) {
            circle.insert(y);
        }
        ans += (ll) circle.size() * (ll) (circle.size() - 1);

        for (int x : circle) {
            vis[x] = 1;
            dfs(dfs, x, 0);
        }
    }
    cout << ans + n << endl;

    return 0;
}

