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
    auto check = [&](int x) {
        map<int, int> mp;
        for (int i = x; i < n; i++) {
            mp[a[i]]++;
        }
        if (mp.size() == 1) return true;
        for (int i = 0; i < n - x; i++) {
            mp[a[i]]++;
            mp[a[i + x]]--;
            if (mp[a[i + x]] == 0) mp.erase(a[i + x]);
            if (mp.size() == 1) return true;
        }
        return false;
    };
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
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

