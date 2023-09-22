#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;

void solve() {
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++) {
            if (s[j] == 'X') {
                int idx = j > 4 ? 10 - j : j + 1;
                if (i == 0 || i == 9) ans += 1;
                else if (i == 1 || i == 8) ans += min(2, idx);
                else if (i == 2 || i == 7) ans += min(3, idx);
                else if (i == 3 || i == 6) ans += min(4, idx);
                else ans += min(5, idx);
            }
        }
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
