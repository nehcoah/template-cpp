#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i < 2) dp[i + 1] = 0;
        else {
            auto t = s.substr(i - 2, 3);
            if (t == "map" || t == "pie") {
                dp[i + 1] = min(dp[i + 1], dp[i - 2] + 1);
            } else {
                dp[i + 1] = dp[i];
            }
        }
    }
    cout << dp.back() << endl;
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
