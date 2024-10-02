#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<int> x(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i] -= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> y(n);
    iota(y.begin(), y.end(), 0);
    while (k) {
        if (k % 2 == 1) {
            for (int i = 0; i < n; i++) {
                y[i] = x[y[i]];
            }
        }
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) {
            tmp[i] = x[x[i]];
        }
        x.swap(tmp);
        k /= 2;
    }

    for (int i = 0; i < n; i++) {
        cout << a[y[i]] << " \n"[i == n - 1];
    }

    return 0;
}

