#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int ss = abs(s[0] - s[1]);
    int tt = abs(t[0] - t[1]);

    if (ss == tt || ss + tt == 5) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

