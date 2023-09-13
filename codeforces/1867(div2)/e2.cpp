#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (n % k != 0) {
        int c = n % k;
        cout << "? " << 1 << endl;
        int x; cin >> x; ans ^= x;
        cout << "? " << 1 + c / 2 << endl;
        cin >> x; ans ^= x;
        cout << "? " << 1 + c << endl;
        cin >> x; ans ^= x;
    }
    int i = n % k == 0 ? 0 : n % k + k;
    while (i < n) {
        cout << "? " << i + 1 << endl;
        int x; cin >> x;
        ans ^= x;
        i += k;
    }
    cout << "! " << ans << endl;
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
