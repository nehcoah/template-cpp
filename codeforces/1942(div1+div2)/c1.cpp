// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x);
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = x - 2;
    for (int i = 0; i < x - 1; i++) {
        if (a[i + 1] - a[i] == 2) ans += 1;
    }
    if (a.back() - a[0] == n - 2) ans += 1;
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
