#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p = (find(a.begin(), a.end(), n) - a.begin()) % 2;
    vector<pair<int, int>> b, c;
    for (int i = p; i < n; i += 2) {
        b.emplace_back(a[i], i);
    }
    for (int i = p ^ 1; i < n; i += 2) {
        c.emplace_back(a[i], i);
    }
    sort(b.begin(), b.end(), greater());
    sort(c.begin(), c.end(), greater());
    vector<int> ans(n);
    int q = 1;
    for (auto [_, i] : c) {
        ans[i] = q++;
    }
    for (auto [_, i] : b) {
        ans[i] = q++;
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
