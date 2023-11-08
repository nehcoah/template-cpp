#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> x(n), l(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> l[i];

    vector<ll> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c.push_back(x[i] - l[j]);
            c.push_back(x[i] + l[j] + 1);
        }
    }
    ranges::sort(c);
    ll ans = 0;
    for (int i = 0; i < c.size() - 1; i++) {
        vector<ll> dis(n);
        for (int j = 0; j < n; j++) dis[j] = abs(x[j] - c[i]);
        bool ok = true;
        ranges::sort(dis);
        for (int j = 0; j < n; j++) {
            if (dis[j] > l[j]) {
                ok = false;
                break;
            }
        }
        if (ok) ans += c[i + 1] - c[i];
    }
    cout << ans << endl;

    return 0;
}

