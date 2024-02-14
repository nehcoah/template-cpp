#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1);
    vector<int> ind(n + 1);
    for (int i = 0; i < k; i++) {
        vector<int> cur(n);
        for (int j = 0; j < n; j++) {
            cin >> cur[j];
        }
        for (int j = 1; j < n - 1; j++) {
            a[cur[j]].push_back(cur[j + 1]);
            ind[cur[j + 1]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) q.push(i);
    }
    vector<int> ans;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : a[x]) {
            if (--ind[y] == 0) q.push(y);
        }
        ans.push_back(x);
    }
    cout << (ans.size() == n ? "YES\n" : "NO\n");
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

