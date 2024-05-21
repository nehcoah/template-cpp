#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    unordered_map<char, int> mp, h, r;
    for (char c : s) {
        mp[c] += 1;
    }
    for (auto &[k, v] : mp) {
        if (v > 1) {
            h[k] += v / 2;
            r[k] += v / 2;
        }
        v %= 2;
    }
    if (mp['N'] == 1 && mp['S'] == 1) {
        if (h.empty()) h['N'] += 1, h['S'] += 1;
        else r['N'] += 1, r['S'] += 1;
        mp['N'] = 0, mp['S'] = 0;
    }
    if (mp['N'] == 1 || mp['S'] == 1) {
        cout << "NO\n";
        return;
    }
    if (mp['W'] == 1 && mp['E'] == 1) {
        if (h.empty()) h['W'] += 1, h['E'] += 1;
        else r['W'] += 1, r['E'] += 1;
        mp['W'] = 0, mp['E'] = 0;
    }
    if (mp['W'] == 1 || mp['E'] == 1) {
        cout << "NO\n";
        return;
    }
    if (h.empty() || r.empty()) {
        cout << "NO\n";
        return;
    }
    string ans;
    for (char c : s) {
        if (h[c] > 0) ans += 'H', h[c] -= 1;
        else ans += 'R', r[c] -= 1;
    }
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
