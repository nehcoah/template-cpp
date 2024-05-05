//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    ll ans = 0;
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    for (int i = 0; i < n; i++) {
        ans = max(ans, sum - a[i] + b[i]);
    }
    cout << ans << endl;

    return 0;
}
