#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), vis(n + 2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
    }
    int x = -1;
    for (int i = 0; i < n + 2; i++) {
        if (!vis[i]) {
            x = i;
            break;
        }
    }
    assert(x != -1);
    if (x == 0) {
        cout << 2 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << 2 << " " << n << "\n";
        return;
    }
    int tot = 0, t = 0;
    vector<int> cnt(x);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] < x) {
            cnt[a[i]] += 1;
            if (cnt[a[i]] == 1) tot += 1;
            if (tot == x) {
                ans.emplace_back(t, i);
                t = i + 1;
                cnt.assign(x, 0);
                tot = 0;
            }
        }
    }
    if (ans.size() < 2) cout << -1 << "\n";
    else {
        ans.back().second = n - 1;
        cout << ans.size() << "\n";
        for (auto [l, r] : ans) {
            cout << l + 1 << " " << r + 1 << "\n";
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
