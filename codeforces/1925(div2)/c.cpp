#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;

    int j = 0;
    string ans;
    bool good = true;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        vector<int> vis(k);
        while (cnt < k && j < m) {
            if (!vis[s[j] - 'a']) cnt += 1;
            vis[s[j] - 'a'] = true;
            j++;
        }
        if (cnt < k) {
            good = false;
            for (int t = 0; t < k; t++) {
                if (!vis[t]) {
                    ans += char('a' + t);
                    break;
                }
            }
        } else {
            ans += s[j - 1];
        }
    }
    if (good) cout << "YES\n";
    else {
        cout << "NO\n";
        cout << ans << endl;
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
