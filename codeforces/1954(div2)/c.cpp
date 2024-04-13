// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    string x, y;
    cin >> x >> y;
    int i = 0;
    while (i < x.size() && x[i] == y[i]) i += 1;
    if (x[i] > y[i]) swap(x, y);
    i += 1;
    while (i < x.size()) {
        if (x[i] < y[i]) swap(x[i], y[i]);
        i += 1;
    }
    cout << x << endl;
    cout << y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
