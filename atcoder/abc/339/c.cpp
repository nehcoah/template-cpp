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

    ll mx = 0, sum = 0;
    for (int x : a) {
        sum += x;
        if (sum < 0) mx = max(mx, -sum);
    }
    cout << mx + sum << endl;

    return 0;
}
