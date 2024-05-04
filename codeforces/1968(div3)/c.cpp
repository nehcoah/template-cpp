//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> x[i];
    }
    vector<int> a(n);
    a.back() = 1e9;
    for (int i = n - 2; i >= 0; i--) {
        a[i] = a[i + 1] - x[i];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
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
