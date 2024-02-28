#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), sum(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    auto check = [&](int l, int u, int x) {
        int cur = sum[x + 1] - sum[l];
        return cur <= u;
    };

    int q;
    cin >> q;
    while (q--) {
        int l, u;
        cin >> l >> u;
        l--;
        int left = l, right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(l, u, mid)) left = mid;
            else right = mid - 1;
        }
        if (left == n - 1) {
            cout << left + 1 << " ";
            continue;
        }
        ll c = 1ll * (u - sum[left + 1] + sum[l] + 1 + u) * (sum[left + 1] - sum[l]) / 2;
        ll d = 1ll * (u - sum[left + 2] + sum[l] + 1 + u) * (sum[left + 2] - sum[l]) / 2;
        if (c < d) cout << left + 2 << " ";
        else cout << left + 1 << " ";
    }
    cout << endl;
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
