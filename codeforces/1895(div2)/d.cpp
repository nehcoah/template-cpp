#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n - 1), b(n);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    for (int i = 1; i < n; i++) b[i] = b[i - 1] ^ a[i - 1];
    for (int i = 30; i >= 0; i--) {
        int cnt = 0;
        for (int x : b) cnt += x >> i & 1;
        if (cnt * 2 > n) {
            for (int &y : b) y ^= 1 << i;
        }
    }
    for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];

    return 0;
}

