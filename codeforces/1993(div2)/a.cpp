#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(4);
    for (char c : s) {
        if (c == '?') continue;
        cnt[c - 'A'] += 1;
    }
    int ans = 0;
    for (int x : cnt) {
        ans += min(n, x);
    }
    cout << ans << "\n";
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

