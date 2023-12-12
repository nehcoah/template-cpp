#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), idx(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int x, int y) { return a[x] < a[y]; });
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[idx[i]];
    }
    vector<int> ans(n);
    for (int i = 0, j = 0; i < n; i++) {
        if (j < i + 1) {
            j = i + 1;
            while (j < n && a[idx[j]] <= sum[j]) j++;
        }
        ans[idx[i]] = j - 1;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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

