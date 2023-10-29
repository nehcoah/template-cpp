#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;
    if (y > x && y - x <= 2) cout << "Yes" << endl;
    else if (y <= x && x - y <= 3) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

