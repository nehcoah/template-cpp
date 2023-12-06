// 30

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n), a(n), b(n), c(n), mx(n), side(n);
    auto check = [&](int x, int i) {
        return a[i] * x * x + b[i] * x + c[i];
    };
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> a[i] >> b[i] >> c[i];
        int t = int(round(-1. * b[i] / (2 * a[i])));
        if (a[i] > 0) {
            if (l[i] < t && t < r[i]) {
                mx[i] = max(check(l[i], i), check(r[i], i));
                side[i] = max(check(l[i] + 1, i), check(r[i] - 1, i));
            } else if (l[i] >= t) {
                mx[i] = check(r[i], i);
                side[i] = check(r[i] - 1, i);
            } else {
                mx[i] = check(l[i], i);
                side[i] = check(l[i] + 1, i);
            }
        } else if (a[i] < 0) {
            if (l[i] < t && t < r[i]) {
                mx[i] = side[i] = check(t, i);
            } else if (l[i] >= t) {
                mx[i] = check(l[i], i);
                side[i] = check(l[i] + 1, i);
            } else {
                mx[i] = check(r[i], i);
                side[i] = check(r[i] - 1, i);
            }
        } else {
            if (b[i] > 0) {
                mx[i] = check(r[i], i);
                side[i] = check(r[i] - 1, i);
            } else if (b[i] < 0) {
                mx[i] = check(l[i], i);
                side[i] = check(l[i] + 1, i);
            } else {
                mx[i] = side[i] = c[i];
            }
        }
    }

    vector<vector<vector<int>>> adj(n, vector<vector<int>>(2));
    vector<vector<int>> ind(n, vector<int>(2));
    for (int i = 0; i < m; i++) {
        int z, x, y;
        cin >> z >> x >> y;
        x--, y--;
        adj[x][z - 1].push_back(y);
        ind[y][z - 1]++;
    }

    if (n <= 10) {
        ll ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            ll res = 0;
            auto cur = ind;
            for (int i = 0; i < n; i++) {
                if ((mask >> i & 1) == 0) continue;
                for (int y : adj[i][0]) {
                    cur[y][0]--;
                }
                for (int y : adj[i][1]) {
                    cur[y][1]--;
                }
            }
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) {
                    if (cur[i][0] == 0) {
                        res += cur[i][1] == 0 ? mx[i] : side[i];
                    }
                }
            }
            ans = max(ans, res);
        }
        cout << ans << endl;
    } else {

    }

    return 0;
}

