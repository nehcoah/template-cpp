#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    ll sum = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < k - 1; i++) {
        sum += a[i] * 2 - 1;
    }
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
