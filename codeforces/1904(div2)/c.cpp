#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k >= 3) {
        cout << 0 << endl;
        return;
    }
    set<ll> s{a.begin(), a.end()};
    ranges::sort(a);
    ll mn = a[0];
    for (int i = 1; i < n; i++) {
        mn = min(mn, a[i] - a[i - 1]);
    }
    if (k == 1) {
        cout << mn << endl;
    } else {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ll x = a[i] - a[j];
                auto it = s.lower_bound(x);
                if (it != s.end()) mn = min(mn, *it - x);
                if (it != s.begin()) mn = min(mn, x - *prev(it));
            }
        }
        cout << mn << endl;
    }

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

