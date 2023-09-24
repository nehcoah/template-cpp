#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> a[i];

    std::sort(a.begin(), a.end());
    for (int i = 1; i < n - 2; i++) x -= a[i];
    if (x - a[0] <= 0) {
        cout << 0 << endl;
        return 0;
    }
    if (x - a.back() > 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << x << endl;

    return 0;
}
