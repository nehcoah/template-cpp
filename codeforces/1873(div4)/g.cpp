#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;

void solve() {
    string s;
    cin >> s;
    bool f = s[0] == 'B' || s.back() == 'B';
    int ans = 0, mn = 1e5 + 1;
    for (int i = 0; i < s.size(); ) {
        int j = i;
        while (j < s.size() && s[j] == s[i]) j++;
        if (s[i] == 'A') {
            ans += j - i;
            mn = min(mn, j - i);
        } else if (j - i > 1) f = true;
        i = j;
    }
    if (!f) ans -= mn;
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
