#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, k;
    cin >> q >> k;
    vector<ll> ans(k + 1);
    ans[0] = 1;
    for (int i = 0; i < q; i++) {
        char c; cin >> c;
        if (c == '+') {
            int x; cin >> x;
            for (int j = k; j >= x; j--) {
                ans[j] = (ans[j] + ans[j - x]) % mod;
            }
        } else {
            int x; cin >> x;
            for (int j = 0; j + x <= k; j++) {
                ans[j + x] = (ans[j + x] - ans[j] + mod) % mod;
            }
        }
        cout << ans[k] << endl;
    }

    return 0;
}
