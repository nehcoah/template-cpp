#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    ll ans = 0;
    for (int l = 0, r = n - 1; l <= r; ) {
        while (l <= r && s[l] == 'R') l += 1;
        while (l <= r && s[r] == 'L') r -= 1;
        if (l > r) break;
        ans += sum[r + 1] - sum[l];
        l += 1, r -= 1;
    }
    cout << ans << "\n";
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

