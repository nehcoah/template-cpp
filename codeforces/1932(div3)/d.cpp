#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    char t;
    cin >> t;
    unordered_map<char, vector<int>> mp{
            {'C', vector<int>(10)},
            {'D', vector<int>(10)},
            {'H', vector<int>(10)},
            {'S', vector<int>(10)},
    };
    for (int i = 0; i < 2 * n; i++) {
        string s; cin >> s;
        mp[s[1]][s[0] - '0']++;
    }

    auto find = [&](char c, int s) {
        for (int i = s + 1; i < 10; i++) {
            if (mp[c][i] > 1) {
                mp[c][i] -= 1;
                return i;
            }
        }
        for (int i = s + 1; i < 10; i++) {
            if (mp[c][i] > 0) {
                mp[c][i] -= 1;
                return i;
            }
        }
        return -1;
    };

    vector<pair<string, string>> ans;
    for (auto &[k, v] : mp) {
        if (k == t) continue;
        while (true) {
            int x = find(k, 0);
            if (x == -1) break;
            int x1 = find(k, x);
            if (x1 == -1) {
                int y = find(t, 0);
                if (y == -1) {
                    cout << "IMPOSSIBLE\n";
                    return;
                }
                ans.emplace_back(string(1, char(x + '0')) + string(1, k), string(1, char(y + '0')) + string(1, t));
            } else {
                ans.emplace_back(string(1, char(x + '0')) + string(1, k), string(1, char(x1 + '0')) + string(1, k));
            }
        }
    }
    while (true) {
        int x = find(t, 0);
        if (x == -1) break;
        int y = find(t, x);
        if (y == -1) {
            cout << "IMPOSSIBLE\n";
            return;
        } else {
            ans.emplace_back(string(1, char(x + '0')) + string(1, t), string(1, char(y + '0')) + string(1, t));
        }
    }
    for (auto [a, b] : ans) {
        cout << a << " " << b << "\n";
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

