#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(4);
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == a[1] && a[2] == a[3]) cout << 2 << endl;
    else if (a[0] == a[1] || a[1] == a[2] || a[2] == a[3]) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}

