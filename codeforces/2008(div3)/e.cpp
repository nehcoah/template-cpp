#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 == 0) {
        vector<vector<int>> cnt(n, vector<int>(26));
        for (int i = 0; i < n; i++) {
            cnt[i % 2][s[i] - 'a'] += 1;
        }
        int ans = n;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ans = min(ans, n / 2 - cnt[0][i] + n / 2 - cnt[1][j]);
            }
        }
        cout << ans << "\n";
    } else {
        vector<vector<int>> suf(2, vector<int>(26)), pre(2, vector<int>(26));
        auto check = [&]() {
            int mx1 = 0, mx2 = 0;
            for (int i = 0; i < 26; i++) {
                mx1 = max(mx1, pre[0][i] + suf[0][i]);
                mx2 = max(mx2, pre[1][i] + suf[1][i]);
            }
            return n - mx1 - mx2;
        };
        for (int i = 0; i < n; i++) {
            suf[(i % 2) ^ 1][s[i] - 'a'] += 1;
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            suf[(i % 2) ^ 1][s[i] - 'a'] -= 1;
            ans = min(ans, check());
            pre[i % 2][s[i] - 'a'] += 1;
        }
        cout << ans << "\n";
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

