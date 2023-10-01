#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        cout << a[idx] - i << endl;
        if (a[idx] == i) idx++;
    }

    return 0;
}
