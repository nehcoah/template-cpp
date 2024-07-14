#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    ll L = accumulate(l.begin(), l.end(), 0ll);
    ll R = accumulate(r.begin(), r.end(), 0ll);
    if (R < 0 || L > 0) cout << "No\n";
    else {
        cout << "Yes\n";
        ll p = -L, sum = 0;
        for (int i = 0; i < n; i++) {
            cout << l[i] + min(r[i] - l[i], p) << " \n"[i == n - 1];
            sum += l[i] + min(r[i] - l[i], p);
            p -= min(r[i] - l[i], p);
        }
        assert(sum == 0);
    }

    return 0;
}
