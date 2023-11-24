#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, sum = 0;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    vector<int> f(sum + 1);
    f[0] = 1;
    for (int y : a) {
        for (int z = sum; z >= y; z--) {
            f[z] |= f[z - y];
        }
    }
    for (int i = x; i <= sum; i++) {
        if (f[i]) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}


