#include "bits/stdc++.h"

using namespace std;
using ll = long long;


void solve() {
    int m, n, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    auto [i1, i2] = minmax_element(a.begin(), a.end());
    int mna = *i1, mxa = *i2;
    auto [j1, j2] = minmax_element(b.begin(), b.end());
    int mnb = *j1, mxb = *j2;

    ll suma = accumulate(a.begin(), a.end(), 0LL);

    if (mxb < mna) {
        if (k & 1) cout << suma << endl;
        else cout << suma + mnb - mxa << endl;
    } else {
        if (k & 1) cout << suma - mna + mxb << endl;
        else cout << suma - mna + mxb - max(mxa, mxb) + min(mna, mnb) << endl;
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

