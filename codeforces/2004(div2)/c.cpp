#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<int> p;
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            p.push_back(a[i] - a[i + 1]);
        }
    }
    sort(p.rbegin(), p.rend());
    ll ans = 0;
    for (int x : p) {
        int cur = min(k, x);
        ans += x - cur;
        k -= cur;
    }
    cout << ans + (n % 2 == 1 ? a.back() : 0) << "\n";
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

