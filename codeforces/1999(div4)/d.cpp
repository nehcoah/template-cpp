#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    string s, t;
    cin >> s >> t;
    int i = 0, j = 0;
    for (; j < t.size(); j++) {
        while (i < s.size() && s[i] != '?' && s[i] != t[j]) i += 1;
        if (i == s.size()) break;
        if (s[i] == '?') s[i] = t[j];
        i += 1;
    }
    if (j == t.size()) {
        for (char &c : s) {
            if (c == '?') c = 'z';
        }
        cout << "YES\n";
        cout << s << "\n";
    } else {
        cout << "NO\n";
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

