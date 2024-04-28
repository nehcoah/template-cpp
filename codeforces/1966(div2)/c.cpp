//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() == 1) {
        cout << "Alice\n";
        return;
    }
    int pre = 0, cnt = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] != pre + 1) {
            cout << (cnt % 2 == 0 ? "Alice\n" : "Bob\n");
            return;
        } else {
            cnt += 1;
        }
        pre = a[i];
    }
    cout << (a.size() % 2 == 1 ? "Alice\n" : "Bob\n");
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
