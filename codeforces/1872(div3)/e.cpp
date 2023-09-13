#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    int ans = 0, sum[n + 1];
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ans ^= a[i];
        sum[i + 1] = sum[i] ^ a[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int l, r;
            cin >> l >> r;
            ans ^= sum[l - 1] ^ sum[r];
        } else {
            int b;
            cin >> b;
            if (b == 1) cout << ans << " ";
            else cout << (ans ^ sum[n]) << " ";
        }
    }
    cout << endl;
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
