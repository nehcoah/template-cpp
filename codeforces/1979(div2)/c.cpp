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
    int x = 1;
    for (int y : a) {
        x = lcm(x, y);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = x / a[i];
    }
    if (accumulate(ans.begin(), ans.end(), 0) >= x) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
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

