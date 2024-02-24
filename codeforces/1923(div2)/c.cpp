#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> sum(n + 1), cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[i + 1] = cnt[i] + (a[i] == 1);
        sum[i + 1] = sum[i] + a[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (l + 1 == r) {
            cout << "No\n";
            continue;
        }
        ll cur = sum[r] - sum[l], c = cnt[r] - cnt[l];
        if (c == 0) {
            cout << "YES\n";
            continue;
        }
        cur -= r - l - c;
        if (2 * c > cur) cout << "NO\n";
        else cout << "YES\n";
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
