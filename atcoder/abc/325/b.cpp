#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> t(24);
    for (int i = 0; i < n; i++) {
        int w, x;
        cin >> w >> x;
        t[x] += w;
    }
    for (int i = 0; i < 24; i++) t.push_back(t[i]);
    ll ans = 0, cur = 0;
    for (int i = 0; i < 9; i++) ans += t[i];
    cur = ans;
    for (int i = 9; i < 48; i++) {
        cur += t[i] - t[i - 9];
        ans = max(ans, cur);
    }
    cout << ans << endl;

    return 0;
}

