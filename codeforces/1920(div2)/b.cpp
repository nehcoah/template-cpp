#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ranges::sort(a, greater<>());
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    int ans = sum.back() - sum[x] * 2;
    for (int i = 0; i < k; i++) {
        ans = max(ans, sum.back() - sum[min(n, x + i + 1)] * 2 + sum[min(n, i + 1)]);
    }
    cout << ans << endl;
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
