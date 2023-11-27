#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, ans = 0;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x >= l) ans++;
    }
    cout << ans << endl;

    return 0;
}


