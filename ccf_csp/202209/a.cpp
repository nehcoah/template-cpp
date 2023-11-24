#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) c[i] = c[i - 1] * a[i];
        else c[i] = a[i];
    }

    for (int i = 0; i < n; i++) {
        if (i < n - 1) b[i] = m % a[i];
        else b[i] = m;
        m /= a[i];
    }

    for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];


    return 0;
}


