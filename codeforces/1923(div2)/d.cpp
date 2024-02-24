#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](bool f) {
        auto c = a;
        if (f) reverse(c.begin(), c.end());
        vector<int> ans(n, n + 1);
        vector<ll> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + c[i];
        }
        for (int i = 0, k = 1; i < n - 1; i++) {
            while (k < n && c[i + 1] == c[k]) k++;
//            int z = lower_bound(sum.begin() + i + 2, sum.end(), c[i], [&](auto x, auto y) {
//                return x - sum[i + 1] <= y;
//            }) - sum.begin();
            int z = *ranges::partition_point(ranges::iota_view(i + 2, n + 1), [&](int v) {
                return sum[v] - sum[i + 1] <= c[i];
            });
            z = max(z, k + 1);
            if (z <= n) ans[i] = z - i - 1;
            if (c[i + 1] > c[i]) ans[i] = 1;
        }
        if (f) reverse(ans.begin(), ans.end());
        return ans;
    };

    auto ans1 = check(false);
    auto ans2 = check(true);
    for (int i = 0; i < n; i++) {
        int x = min(ans1[i], ans2[i]);
        cout << (x >= n ? -1 : x) << " \n"[i == n - 1];
    }
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
