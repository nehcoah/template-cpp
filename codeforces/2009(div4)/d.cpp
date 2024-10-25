#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[y].push_back(x);
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    vector<unordered_set<int>> st{
            {a[0].begin(), a[0].end()},
            {a[1].begin(), a[1].end()}
    };
    ll ans = 0;
    for (int x : a[0]) {
        if (st[1].contains(x)) {
            ans += a[0].size() - 1;
        }
        if (st[0].contains(x + 2) && st[1].contains(x + 1)) {
            ans += 1;
        }
    }
    for (int x : a[1]) {
        if (st[0].contains(x)) {
            ans += a[1].size() - 1;
        }
        if (st[1].contains(x + 2) && st[0].contains(x + 1)) {
            ans += 1;
        }
    }
    cout << ans << "\n";

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

