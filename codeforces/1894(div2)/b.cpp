#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> idx(101);
    for (int i = 0; i < n; i++) cin >> a[i], idx[a[i]].push_back(i);
    vector<int> ans(n, 1);
    bool ok1 = false, ok2 = false;
    for (int i = 0; i < 101; i++) {
        if (idx[i].size() < 2) continue;
        if (!ok1) {
            for (int j = 0; j < idx[i].size() - 1; j++) ans[idx[i][j]] = 1;
            ans[idx[i].back()] = 2;
            ok1 = true;
        } else {
            for (int j = 0; j < idx[i].size() - 1; j++) ans[idx[i][j]] = 2;
            ans[idx[i].back()] = 3;
            ok2 = true;
        }
    }
    if (ok2) for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
    else cout << -1 << endl;
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

