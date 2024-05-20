#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h;
    cin >> h;

    int x = 1;
    for (int i = 1; ; i++) {
        if (x > h) {
            cout << i << endl;
            return 0;
        }
        x = x * 2 + 1;
    }

    return 0;
}
