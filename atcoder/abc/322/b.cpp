#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    string s, t;
    cin >> s >> t;

    bool pre = false, suf = false;
    if (t.substr(0, n) == s) pre = true;
    if (t.substr(m - n, n) == s) suf = true;

    if (pre && suf) cout << 0 << endl;
    else if (pre) cout << 1 << endl;
    else if (suf) cout << 2 << endl;
    else cout << 3 << endl;

    return 0;
}
