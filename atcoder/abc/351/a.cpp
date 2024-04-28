//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 9, m = 8;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int A; cin >> A;
        a += A;
    }
    for (int i = 0; i < m; i++) {
        int B; cin >> B;
        b += B;
    }
    cout << a - b + 1 << endl;

    return 0;
}
