//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> c(101);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        c[a] += 1;
    }
    int ans = 0;
    for (int x : c) {
        if (x >= k) {
            cout << k - 1 << endl;
            return;
        } else {
            ans += x;
        }
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
