#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a += x;
        b += y;
    }
    if (a == b) cout << "Draw\n";
    else if (a < b) cout << "Aoki\n";
    else cout << "Takahashi\n";

    return 0;
}
