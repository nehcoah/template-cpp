#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int B = 400;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> ans(q);
    vector<vector<array<int, 3>>> t(n + 1);
    for (int i = 0; i < q; i++) {
        int s, d, k;
        cin >> s >> d >> k;
        s--;
        if (d > B) {
            for (int j = 0; j < k; j++) {
                ans[i] += a[s + j * d] * (j + 1);
            }
        } else {
            t[d].push_back({s, k, i});
        }
    }
    for (int d = 0; d <= n; d++) {
        if (t[d].empty()) continue;
        vector<ll> sum(n + B + 1), k_sum(n + B + 1);
        for (int i = 0; i < n; i++) {
            sum[i + d] = sum[i] + a[i];
            k_sum[i + d] = k_sum[i] + 1ll * a[i] * (i / d + 1);
        }
        for (auto [s, k, i] : t[d]) {
            ans[i] = k_sum[s + d * k] - k_sum[s] - (s / d) * (sum[s + d * k] - sum[s]);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << " \n"[i == q - 1];
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
