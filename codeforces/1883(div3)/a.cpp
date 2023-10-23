#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int pre = 1, ans = 0;
    for (char c : s) {
        int cur = c - '0';
        ans += cur == 0 ? abs(10 - pre) + 1 : abs(cur - pre) + 1;
        pre = cur == 0 ? 10 : cur;
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

