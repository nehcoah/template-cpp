// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n, 1);
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        a[t - 1] ^= 1;
    }
    cout << accumulate(a.begin(), a.end(), 0) << endl;

    return 0;
}
