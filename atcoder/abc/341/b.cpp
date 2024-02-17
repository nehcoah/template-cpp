#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        ll s, t;
        cin >> s >> t;
        a[i + 1] += a[i] / s * t;
    }
    cout << a.back() << endl;

    return 0;
}

