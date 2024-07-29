#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector f(n + 1, vector<int>(x + 1, 1e9));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int c = i; c >= 0; c--) {
            for (int p = x; p - a[i] >= 0; p--) {
                f[c + 1][p] = min(f[c + 1][p], f[c][p - a[i]] + b[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int t = 0; t <= x; t++) {
            if (f[i][t] <= y) ans = max(ans, i + 1);
        }
    }
    cout << ans << endl;


    return 0;
}
