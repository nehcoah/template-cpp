#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (mp.contains(a[i])) {
            ans.push_back(mp[a[i]] + 1);
        } else {
            ans.push_back(-1);
        }
        mp[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}

