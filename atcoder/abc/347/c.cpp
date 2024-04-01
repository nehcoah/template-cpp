#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        d[i] %= a + b;
        if (d[i] == 0) d[i] = a + b;
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < n; i++) {
        d.push_back(d[i] + a + b);
    }
    ll mn = d[0], mx = d[n - 1];
    if (mx - mn < a) {
        cout << "Yes\n";
        return 0;
    }
    for (int i = n; i < n * 2; i++) {
        mx = d[i];
        mn = d[i - n + 1];
        if (mx - mn < a) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

    return 0;
}
