#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h, w, n;
    cin >> h >> w >> n;
    vector<int> t(n), a(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> x[i];
        a[i]--;
    }

    vector<int> row(h), col(w);
    ll r = h, c = w;
    map<int, ll> mp;
    for (int i = n - 1; i >= 0; i--) {
        if (t[i] == 1) {
            if (!row[a[i]] && c) {
                mp[x[i]] += c;
                row[a[i]] = true;
                r -= 1;
            }
        } else {
            if (!col[a[i]] && r) {
                mp[x[i]] += r;
                col[a[i]] = true;
                c -= 1;
            }
        }
    }
    ll sum = 0;
    for (auto [k, v] : mp) {
        if (k != 0) sum += v;
    }
    if (sum != 1ll * h * w) mp[0] = 1ll * h * w - sum;
    cout << mp.size() << endl;
    for (auto [k, v] : mp) {
        cout << k << " " << v << endl;
    }

    return 0;
}
