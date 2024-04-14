// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int a; cin >> a;
        ans += a;
    }
    cout << -ans << endl;

    return 0;
}
