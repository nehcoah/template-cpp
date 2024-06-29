#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (a[i] > b[i]) A += a[i];
            else B += b[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == -1) (A < B ? B : A) += a[i];
            else (A < B ? A : B) += a[i];
        }
    }
    cout << min(A, B) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
