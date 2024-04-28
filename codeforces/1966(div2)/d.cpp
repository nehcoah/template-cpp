//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    int p = 0;
    while (1 << (p + 1) <= k) p += 1;

    vector<int> ans;
    for (int i = 0; i < p; i++) {
        ans.push_back(1 << i);
    }
    if (k != 1 << p) ans.push_back(k - (1 << p));
    if (n >= k + 1) ans.push_back(k + 1);
    if (n >= k + 1 + (1 << p)) ans.push_back(k + 1 + (1 << p));
    for (int i = p + 1; 1 << i <= n; i++) {
        ans.push_back(1 << i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
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
