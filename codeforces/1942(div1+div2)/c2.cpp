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
    vector<pair<int, int>> info;
    int ans = x - 2;
    for (int i = 0; i < x - 1; i++) {
        int d = a[i + 1] - a[i];
        if (d == 1) continue;
        if (d == 2) ans += 1;
        else if (d % 2 == 0) info.emplace_back(d / 2 - 1, d / 2);
        else info.emplace_back(d / 2, d / 2);
    }
    int d = a[0] + n - a.back();
    if (d == 2) ans += 1;
    else if (d % 2 == 0) info.emplace_back(d / 2 - 1, d / 2);
    else if (d > 1) info.emplace_back(d / 2, d / 2);
    sort(info.begin(), info.end(), [](auto &s, auto &t) {
        double sx = 1. * s.second / s.first, tx = 1. * t.second / t.first;
        return sx == tx ? s.first < t.first : sx > tx;
    });
    for (auto [k, v] : info) {
        if (y < k) {
            ans += 2 * y;
            break;
        }
        ans += v + k;
        y -= k;
    }
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
