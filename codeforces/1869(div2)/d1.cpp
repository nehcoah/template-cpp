#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

ll pow2[40];
auto init = [](){
    pow2[0] = 1;
    for (int i = 1; i < 40; i++) pow2[i] = pow2[i - 1] * 2;
    return 0;
}();

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum % n != 0) {
        cout << "No" << endl;
        return;
    }
    ll avg = sum / n;
    int vis[40];
    memset(vis, 0, sizeof(vis));
    for (ll x : a) {
        ll sub = abs(x - avg);
        if (sub == 0) continue;
        ll cur = *upper_bound(pow2, pow2 + 40, sub);
        if (__builtin_popcountll(cur - sub) != 1) {
            cout << "No" << endl;
            return;
        }
        int c1 = __builtin_ctzll(cur), c2 = __builtin_ctz(cur - sub);
        if (x > avg) {
            vis[c1]++;
            vis[c2]--;
        } else {
            vis[c1]--;
            vis[c2]++;
        }
    }
    for (int x : vis) if (x != 0) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
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
