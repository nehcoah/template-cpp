#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;

    if ((n ^ m) < n) {
        cout << 1 << endl;
        cout << n << " " << m << endl;
        return;
    }

    int i = 62;
    while ((n >> i & 1) == (m >> i & 1)) {
        i--;
    }
    int j = i - 1;
    while (j >= 0 && (n >> j & 1) == 0) {
        if (m >> j & 1) {
            cout << -1 << endl;
            return;
        }
        j--;
    }
    ll k = (n ^ (1ll << i)) | ((1ll << (j + 1)) - 1);
    cout << 2 << endl;
    cout << n << " " << k << " " << m << endl;

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
