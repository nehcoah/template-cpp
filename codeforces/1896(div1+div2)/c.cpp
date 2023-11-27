#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), idx(n), ans(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int i, int j) { return a[i] < a[j]; });
    ranges::sort(b);
    for (int i = x == 0 ? 0 : n - x, j = 0; j < n; j++, i = (i + 1) % n) {
        ans[idx[i]] = b[j];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += a[i] > ans[i];
    if (cnt == x) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
    } else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}


