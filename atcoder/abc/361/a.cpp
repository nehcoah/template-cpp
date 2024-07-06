#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.insert(a.begin() + k, x);
    for (int i = 0; i < n + 1; i++) {
        cout << a[i] << " \n"[i == n];
    }

    return 0;
}
