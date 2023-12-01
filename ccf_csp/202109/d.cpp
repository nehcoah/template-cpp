#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<double>> f(1 << n, vector<double>(n * k, -1));
    function<double(int, int, int)> dfs = [&](int mask, int cnt, int d) -> double {
        if (mask == (1 << n) - 1) return d;
        if (cnt >= (n - __builtin_popcount(mask)) * k) return d;
        if (f[mask][cnt] != -1) return f[mask][cnt];
        double ans = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                ans += dfs(mask, cnt + 1, d + 1) * a[i];
            } else {
                ans += dfs(mask | (1 << i), cnt, d + 1) * a[i];
            }
        }
        return f[mask][cnt] = ans;
    };
    cout << fixed << setprecision(10) << dfs(0, 0, 0) << "\n";

    return 0;
}


