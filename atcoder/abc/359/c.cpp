#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    if ((sx + sy) % 2 == 1) {
        sx -= 1;
    }
    if ((tx + ty) % 2 == 1) {
        tx -= 1;
    }
    cout << max((abs(sx - tx) + abs(sy - ty)) / 2, abs(sy - ty)) << endl;

    return 0;
}
