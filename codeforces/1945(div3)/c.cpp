#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + (s[i] == '1');
    }
    int ans = -1;
    double mn = n;
    for (int i = 0; i <= n; i++) {
        int l = i - sum[i], r = sum.back() - sum[i];
        if (2 * l >= i && r * 2 >= (n - i)) {
            if (abs(1. * n / 2 - i) < mn) {
                ans = i, mn = abs(n / 2 - i);
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
