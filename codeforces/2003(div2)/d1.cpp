#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, m;
    cin >> n >> m;

    int x = 0;
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        vector<int> cnt(l + 2);
        for (int j = 0; j < l; j++) {
            int a; cin >> a;
            if (a <= l + 1) cnt[a] += 1;
        }
        int a = 0;
        while (cnt[a] > 0) a += 1;
        a += 1;
        while (cnt[a] > 0) a += 1;
        x = max(a, x);
    }

    if (x <= m) cout << 1ll * x * x + 1ll * (x + m) * (m - x + 1) / 2 << "\n";
    else cout << 1ll * x * (m + 1) << "\n";
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

