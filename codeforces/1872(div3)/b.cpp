#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> t;
    for (int i = 0; i < n; i++) {
        int d, s;
        cin >> d >> s;
        t.emplace_back(d, s);
    }
    sort(t.begin(), t.end());
    int ans = 1001;
    for (int i = 0; i < n; i++) {
        auto [d, s] = t[i];
        ans = min(ans, d + (s - 1) / 2);
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
