#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int cnt = 1;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1]) cnt += 1;
    }
    if (s[0] == '0') {
        cout << max(1, cnt - 1) << "\n";
    } else {
        if (cnt == 1) cout << 1 << "\n";
        else cout << max(2, cnt - 1) << "\n";
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
