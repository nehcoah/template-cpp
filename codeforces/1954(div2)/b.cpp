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
    assert(a[0] == a.back());
    int pre = -1, ans = n + 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != a[0]) {
            ans = min(ans, i - pre - 1);
            pre = i;
        }
    }
    if (pre != -1) ans = min(ans, n - pre - 1);
    cout << (ans == n + 1 ? -1 : ans) << endl;
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
