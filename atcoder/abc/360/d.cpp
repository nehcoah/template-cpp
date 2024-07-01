#include "bits/stdc++.h"
using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<ll> a, b;
    for (int i = 0; i < n; i++) {
        (s[i] == '1' ? a : b).push_back(x[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            int l = lower_bound(b.begin(), b.end(), x[i]) - b.begin();
            int r = upper_bound(b.begin(), b.end(), x[i] + 2 * t) - b.begin() - 1;
            ans += r - l + 1;
        } else {
//            int l = lower_bound(a.begin(), a.end(), x[i] - 2 * t) - a.begin();
//            int r = upper_bound(a.begin(), a.end(), x[i]) - a.begin() - 1;
//            ans += r - l + 1;
        }
    }
    cout << ans << endl;

    return 0;
}
