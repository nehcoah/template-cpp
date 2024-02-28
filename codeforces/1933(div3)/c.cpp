#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int a, b, l;
    cin >> a >> b >> l;
    int x = 0, y = 0;
    for (int z = a; ; z *= a) {
        if (l % z == 0) x++;
        else break;
    }
    for (int z = b; ; z *= b) {
        if (l % z == 0) y++;
        else break;
    }
    set<int> st;
    for (int i = 0, c = 1; i <= x; i++, c *= a) {
        int cur = l / c;
        for (int j = 0, d = 1; j <= y; j++, d *= b) {
            if (cur % d == 0) {
                st.insert(cur / d);
            }
        }
    }
    cout << st.size() << endl;
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
