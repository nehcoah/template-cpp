#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[0] += c;
    int t = max_element(a.begin(), a.end()) - a.begin();
    ll sum = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i == t) ans[i] = 0;
        else if (i < t) ans[i] = i + (sum < a[t]);
        else ans[i] = i;
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

