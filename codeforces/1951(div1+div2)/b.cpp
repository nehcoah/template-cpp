// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    k -= 1;
    vector<int> a(n), mx(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) mx[i] = a[i];
        else mx[i] = max(mx[i - 1], a[i]);
    }
    set<int> idx;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[k]) idx.insert(i);
    }
    int ans = 0;
    if (k == 0 || mx[k - 1] < a[k]) {
        auto it = idx.lower_bound(k);
        ans = max(ans, (it == idx.end() ? n : *it) - k - (k == 0));
    }
    for (int i = 0; i < n; i++) {
        if (i == k) continue;
        if (a[i] > a[k] && i < k) {
            idx.erase(i);
            idx.insert(k);
            if (i == 0 || mx[i - 1] < a[k]) {
                auto it = idx.lower_bound(i);
                ans = max(ans, (it == idx.end() ? n : *it) - i - (i == 0));
            }
            idx.insert(i);
            idx.erase(k);
        } else {
            if (i == 0 || mx[i - 1] < a[k]) {
                auto it = idx.lower_bound(i);
                ans = max(ans, (it == idx.end() ? n : *it) - i - (i == 0));
            }
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
