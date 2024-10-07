#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, t;
    cin >> n >> s >> t;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    double ans = 1e9;
    auto dfs = [&](auto self, int x, int y, int mask, double cur) {
        if (mask == (1 << n) - 1) {
            ans = min(ans, cur);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) continue;
            double to_ab = hypot(x - a[i], y - b[i]) / s;
            double to_cd = hypot(x - c[i], y - d[i]) / s;
            double draw = hypot(a[i] - c[i], b[i] - d[i]) / t;
            self(self, a[i], b[i], mask | (1 << i), cur + to_cd + draw);
            self(self, c[i], d[i], mask | (1 << i), cur + to_ab + draw);
        }
    };
    dfs(dfs, 0, 0, 0, 0);
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}

