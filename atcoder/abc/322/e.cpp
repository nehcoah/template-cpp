#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, p;
    cin >> n >> k >> p;

    vector<int> pw(k + 1);
    pw[0] = 1;
    for (int i = 1; i <= k; i++) pw[i] = pw[i - 1] * (p + 1);

    vector f(n + 1, vector<ll>(pw.back(), 1e12));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        vector<int> a(k);
        for (int j = 0; j < k; j++) cin >> a[j];

        for (int j = 0; j < pw.back(); j++) {
            f[i + 1][j] = min(f[i + 1][j], f[i][j]);
            int x = 0;
            for (int l = 0; l < k; l++) {
                int y = j / pw[l] % (p + 1);
                y = min(y + a[l], p);
                x += y * pw[l];
            }
            f[i + 1][x] = min(f[i + 1][x], f[i][j] + c);
        }
    }

    if (f[n][pw.back() - 1] == 1e12) cout << -1 << endl;
    else cout << f[n][pw.back() - 1] << endl;

    return 0;
}
