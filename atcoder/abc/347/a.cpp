#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % k == 0) cout << x / k << " ";
    }
    cout << endl;

    return 0;
}
