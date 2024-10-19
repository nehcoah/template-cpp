#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int i = 0, j = 0;
    int ans = -1;
    for (; i < n; i++) {
        if (a[i] > b[j]) {
            if (ans != -1) {
                cout << -1 << endl;
                return 0;
            }
            ans = a[i];
        } else {
            j += 1;
        }
    }
    cout << ans << endl;

    return 0;
}

