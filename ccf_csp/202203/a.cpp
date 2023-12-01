#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    v[0] = 1;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        if (!v[r]) ans++;
        v[l] = 1;
    }
    cout << ans << endl;

    return 0;
}


