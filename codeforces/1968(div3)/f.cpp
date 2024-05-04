//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), sum(n + 1);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] ^ a[i];
    }
    for (int i = 0; i <= n; i++) {
        mp[sum[i]].push_back(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l -= 1, r -= 1;
        if (sum[l] == sum[r + 1]) {
            cout << "YES\n";
            continue;
        }
        auto it = lower_bound(mp[sum[r + 1]].begin(), mp[sum[r + 1]].end(), l + 1);
        if (it == mp[sum[r + 1]].end() || *it > r) {
            cout << "NO\n";
            continue;
        }
        int l1 = *it;
        it = lower_bound(mp[sum[l]].begin(), mp[sum[l]].end(), l1 + 1);
        if (it == mp[sum[l]].end() || *it > r) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
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
