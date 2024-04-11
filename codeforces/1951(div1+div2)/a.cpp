// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = count(s.begin(), s.end(), '1');
    if (cnt % 2 == 1) {
        cout << "NO\n";
    } else {
        if (cnt == 2) {
            auto p = s.find('1');
            if (s[p + 1] == '1') {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        } else {
            cout << "YES\n";
        }
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
