#include "bits/stdc++.h"
using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (accumulate(a.begin(), a.end(), 0ll) <= m) {
        cout << "infinite\n";
        return 0;
    }

    ll l = 0, r = m;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += min(a[i], mid);
            if (sum > m) break;
        }
        if (sum > m) r = mid - 1;
        else l = mid;
    }
    cout << l << endl;

    return 0;
}
