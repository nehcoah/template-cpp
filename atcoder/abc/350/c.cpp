// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= 1;
        mp[a[i]] = i;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == i) continue;
        ans.emplace_back(i, mp[i]);
        swap(a[i], a[mp[i]]);
        swap(mp[a[i]], mp[a[mp[i]]]);
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << endl;
    }

    return 0;
}
