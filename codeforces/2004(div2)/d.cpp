#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    map<string, set<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        mp[s[i]].insert(i);
    }

    vector<string> p{"BR", "BG", "BY", "GR", "GY", "RY"};
    auto check = [&](int x, int y, string cur) {
        int ok = 0;
        for (char c : cur) {
            for (char c1 : s[x]) {
                if (c == c1) ok |= 1;
            }
            for (char c2 : s[y]) {
                if (c == c2) ok |= 2;
            }
        }
        return ok == 3;
    };

    while (q--) {
        int x, y; cin >> x >> y;
        x -= 1, y -= 1;
        if (x > y) swap(x, y);
        int ans = -1;
        for (auto &cur : p) {
            if (!check(x, y, cur)) continue;
            if (!mp.contains(cur)) continue;
            auto it = mp[cur].lower_bound(x);
            if (it != mp[cur].end()) {
                if (ans == -1 || ans > abs(*it - x) + abs(*it - y)) {
                    ans = abs(*it - x) + abs(*it - y);
                }
            }
            if (it != mp[cur].begin()) {
                it = prev(it);
                if (ans == -1 || ans > abs(*it - x) + abs(*it - y)) {
                    ans = abs(*it - x) + abs(*it - y);
                }
            }
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

