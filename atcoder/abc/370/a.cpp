#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r;
    cin >> l >> r;

    if (l == 1 && r == 0) cout << "Yes\n";
    else if (l == 0 && r == 1) cout << "No\n";
    else cout << "Invalid\n";

    return 0;
}

