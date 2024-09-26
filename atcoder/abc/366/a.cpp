#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, a;
    cin >> n >> t >> a;
    int th = n % 2 == 1 ? (n + 1) / 2 : n / 2 + 1;
    if (max(t, a) >= th) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

