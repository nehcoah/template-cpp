#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    int more = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > sum) more += a[i] - sum;
        if (a[i] < sum) {
            if (more < sum - a[i]) {
                cout << "NO\n";
                return;
            } else more -= sum - a[i];
        }
    }
    cout << "YES\n";
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

