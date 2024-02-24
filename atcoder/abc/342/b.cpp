#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        mp[p] = i;
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (mp[a] < mp[b]) cout << a << "\n";
        else cout << b << "\n";
    }

    return 0;
}
