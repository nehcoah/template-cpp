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
    map<int, pair<vector<int>, vector<int>>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i] & (-1 << 2)].first.push_back(i);
        mp[a[i] & (-1 << 2)].second.push_back(a[i]);
    }
    vector<int> ans(n);
    for (auto &[k, v] : mp) {
        sort(v.first.begin(), v.first.end());
        sort(v.second.begin(), v.second.end());
        for (int i = 0; i < v.first.size(); i++) {
            ans[v.first[i]] = v.second[i];
        }
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
