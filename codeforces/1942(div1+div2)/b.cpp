// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> p(n), vis(n + 1);
    p[0] = a[0] < 0 ? -a[0] : 0;
    int mex = a[0] < 0 ? 0 : 1;
    vis[p[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > 0) {
            p[i] = mex;
        } else {
            p[i] = mex - a[i];
        }
        vis[p[i]] = 1;
        while (vis[mex]) mex += 1;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
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
