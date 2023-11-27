#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (a[i] >= l && a[i] <= r) cout << a[i] << " \n"[i == n - 1];
        else {
            if (a[i] < l) cout << l << " \n"[i == n - 1];
            else cout << r << " \n"[i == n - 1];
        }
    }

    return 0;
}


