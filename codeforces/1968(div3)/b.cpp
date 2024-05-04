//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    int i = 0, j = 0;
    while (i < n && j < m) {
        while (j < m) {
            if (a[i] != b[j]) j += 1;
            else break;
        }
        if (j < m) i += 1, j += 1;
    }
    cout << i << endl;
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
