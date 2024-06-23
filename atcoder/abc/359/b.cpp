#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < 2 * n - 1; i++) {
        if (a[i - 1] == a[i + 1]) ans += 1;
    }
    cout << ans << endl;

    return 0;
}
