#include "bits/stdc++.h"

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
    }

    vector suf(n, vector<int>(11, -1));
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1];
        suf[i][a[i + 1]] = i + 1;
    }

    vector<int> mn(n, n + 1);
    for (int i = 0; i < n; i++) {
        for (int x = 1; x <= 10; x++) {
            int d = x - a[i];
            int y = a[i] + 2 * d;
            if (suf[i][x] != -1 && y >= 1 && y <= 10 && suf[suf[i][x]][y] != -1) {
                mn[i] = min(mn[i], suf[suf[i][x]][y]);
            }
        }
    }

    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) mn[i] = min(mn[i], mn[i + 1]);
        if (mn[i] < n) ans += n - mn[i];
    }
    cout << ans << endl;

    return 0;
}
