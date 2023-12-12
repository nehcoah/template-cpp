#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n), p(n), d(n), sum(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        d[i] = d[p[i] - 1] + 1;
    }
    for (int i = 0; i < n; i++) {
        sum[d[i]] += a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (sum[i] > 0) {
            cout << "+\n";
            return 0;
        } else if (sum[i] < 0) {
            cout << "-\n";
            return 0;
        }
    }
    cout << "0\n";

    return 0;
}

