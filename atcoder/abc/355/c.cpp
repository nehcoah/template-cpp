#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<int> a(t);
    for (int i = 0; i < t; i++) {
        cin >> a[i];
        a[i] -= 1;
    }
    vector<int> row(n), col(n);
    int p = 0, q = 0;
    for (int i = 0; i < t; i++) {
        int x = a[i] / n;
        int y = a[i] % n;
        if (x + y == n - 1) p += 1;
        if (x == y) q += 1;
        row[x] += 1;
        col[y] += 1;
        if (p == n || q == n || row[x] == n || col[y] == n) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
