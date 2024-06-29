#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    auto get = [&](int l, int r) {
        return stoi(s.substr(l, r - l + 1));
    };

    if (count(s.begin(), s.end(), '0')) {
        if (n > 3) cout << 0 << endl;
        else if (n == 3) {
            cout << min({get(0, 0) + get(1, 2), get(0, 0) * get(1, 2),
                         get(0, 1) + get(2, 2), get(0, 1) * get(2, 2),
                         get(0, 2)}) << endl;
        } else cout << stoi(s) << endl;
        return;
    }

    vector f(n, vector<ll>(n - 1, -1));
    auto dfs = [&](auto self, int i, int cnt) -> ll {
        if (i == n) {
            return cnt == 0 ? 0 : 1e18;
        }
        if (cnt == 0) {
            int t = get(i, n - 1);
            return t == 1 ? 0 : t;
        }
        if (n - i < cnt) return 1e18;
        if (f[i][cnt] != -1) return f[i][cnt];
        ll ans = 1e18;
        for (int j = i; n - j >= cnt; j++) {
            int t = get(i, j);
            if (t == 1) ans = min(ans, self(self, j + 1, cnt - 1));
            else ans = min(ans, self(self, j + 1, cnt - 1) + t);
        }
        return f[i][cnt] = ans;
    };

//    cout << dfs(dfs, 0, n - 2) << " " << dfs(dfs, 0, max(0, n - 3)) << endl;
    cout << min(dfs(dfs, 0, n - 2), dfs(dfs, 0, max(0, n - 3))) << endl;
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
