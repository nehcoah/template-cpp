#include "bits/stdc++.h"
using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int y;
    cin >> y;

    if (y % 4 != 0) cout << 365 << endl;
    else if (y % 4 == 0 && y % 100 != 0) cout << 366 << endl;
    else if (y % 100 == 0 && y % 400 != 0) cout << 365 << endl;
    else cout << 366 << endl;

    return 0;
}
