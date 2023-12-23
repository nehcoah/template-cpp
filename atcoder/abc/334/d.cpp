#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    ranges::sort(r);
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + r[i];
    }
    for (int i = 0; i < q; i++) {
        ll x; cin >> x;
        int y = upper_bound(sum.begin(), sum.end(), x) - sum.begin() - 1;
        cout << y << "\n";
    }

    return 0;
}

