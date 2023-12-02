#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, D, y, m, d;
    cin >> M >> D >> y >> m >> d;

    d += 1;
    if (d > D) d = 1, m += 1;
    if (m > M) m = 1, y += 1;
    cout << y << " " << m << " " << d << endl;

    return 0;
}


