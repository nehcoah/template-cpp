#include "bits/stdc++.h"

using namespace std;
using ll = long long;

template<class T>
constexpr T power(T a, ll b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll b;
    cin >> b;

    for (ll x = 1; ; x++) {
        ll cur = power(x, x);
        if (cur == b) {
            cout << x << endl;
            return 0;
        }
        if (cur > b) break;
    }
    cout << -1 << endl;

    return 0;
}

