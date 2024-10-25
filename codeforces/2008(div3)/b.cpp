#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int x = sqrt(n);
    if (x * x != n) {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < x; i++) {
        auto cur = s.substr(i * x, x);
        if (i == 0 || i == x - 1) {
            if (count(cur.begin(), cur.end(), '1') != x) {
                cout << "No\n";
                return;
            }
        } else {
            if (cur[0] != '1' || cur.back() != '1' || count(cur.begin(), cur.end(), '0') != x - 2) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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

