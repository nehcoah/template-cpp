#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll s;
    cin >> n >> s;
    vector<int> a(n);
    vector<ll> f(n + 1), sum(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        int x = upper_bound(sum.begin(), sum.end(), sum[i] + s) - sum.begin();
        f[i] = f[x - 1] + n - i;
    }
    cout << accumulate(f.begin(), f.end(), 0ll) << endl;

    return 0;
}

