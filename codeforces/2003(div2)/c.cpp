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
    vector<int> cnt(26);
    for (char c : s) {
        cnt[c - 'a'] += 1;
    }
    int p = 0;
    for (int i = 0; i < n; i++) {
        while (cnt[p] == 0) p = (p + 1) % 26;
        cout << char(p + 'a');
        cnt[p] -= 1;
        p = (p + 1) % 26;
    }
    cout << "\n";
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

