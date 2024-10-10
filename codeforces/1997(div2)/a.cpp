#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i]) {
            s.insert(s.begin() + i, s[i] == 'a' ? 'z' : 'a');
            cout << s << "\n";
            return;
        }
    }
    s += s.back() == 'a' ? 'z' : 'a';
    cout << s << "\n";
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

