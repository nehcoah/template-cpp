#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n + 1; i++) {
        cin >> b[i];
    }
    ll ans = 0, f = 1e9;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
        if (b.back() >= min(a[i], b[i]) && b.back() <= max(a[i], b[i])) f = 1;
        else if (b.back() > max(a[i], b[i])) f = min(f, 1ll * abs(b.back() - max(a[i], b[i])) + 1);
        else if (b.back() < min(a[i], b[i])) f = min(f, 1ll * abs(b.back() - min(a[i], b[i])) + 1);
    }
    cout << ans + f << endl;
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
