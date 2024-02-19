#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + s[i] - '0';
    }
    string ans;
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur += sum[i + 1];
        ans += char(cur % 10 + '0');
        cur /= 10;
    }
    while (cur > 0) {
        ans += char(cur % 10 + '0');
        cur /= 10;
    }
    while (ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
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

