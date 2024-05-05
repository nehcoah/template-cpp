//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    if (x > y) swap(x, y);

    if (x <= z && z <= y) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
