// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    int ans = 0, cur = -1;
    for (int mask = 0; mask < 1 << n; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                int j = i;
                while (j < n && mask >> j & 1) j += 1;
                sum += (j - i) * (j - i);
                i = j - 1;
            } else {
                sum += a[i];
            }
        }
        if (ans < sum) ans = sum, cur = mask;
    }

    vector<pair<int, int>> op;
    auto check = [&](auto self, int l, int r) -> void {
        for (int i = r; i > l + 1; i--) {
            self(self, l + 1, i);
            if (l + 1 < i - 1) {
                op.emplace_back(l + 1, i - 1);
            }
        }
        op.emplace_back(l, r);
    };
    for (int i = 0; i < n; i++) {
        if (cur >> i & 1) {
            int j = i;
            while (j < n && cur >> j & 1) j += 1;
            for (int k = i; k < j; k++) {
                if (a[k] != 0) op.emplace_back(k, k + 1);
            }
            check(check, i, j);
            i = j - 1;
        }
    }
    cout << ans << " " << op.size() << endl;
    for (auto [l, r] : op) {
        cout << l + 1 << " " << r << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
