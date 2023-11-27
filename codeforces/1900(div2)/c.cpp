#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> l(n, -1), r(n, -1);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x != 0) l[i] = x - 1;
        if (y != 0) r[i] = y - 1;
    }

    int ans = 1e9;
    auto dfs = [&](auto self, int x, int c) {
        if (l[x] == -1 && r[x] == -1) {
            ans = min(ans, c);
            return;
        }
        if (l[x] != -1) self(self, l[x], c + (s[x] != 'L'));
        if (r[x] != -1) self(self, r[x], c + (s[x] != 'R'));
    };
    dfs(dfs, 0, 0);
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


