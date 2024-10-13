#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    string s;
    cin >> s;
    if (s.size() > 2 && s.substr(0, 2) == "10") {
        auto p = s.substr(2);
        if (p[0] != '0' && stoi(p) >= 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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

