#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    set<int> st;
    auto check = [&](int t) {
        if (t % 2 == 0 && t / 2 + 1 >= x) st.insert(t);
        for (int i = 2; i * i <= t; i++) {
            if (t % i == 0 && i % 2 == 0 && i / 2 + 1 >= x) {
                st.insert(i);
            }
            if (t % i == 0) {
                int y = t / i;
                if (y != i && y % 2 == 0 && y / 2 + 1 >= x) {
                    st.insert(y);
                }
            }
        }
    };
    check(n - x);
    if (x > 1) check(n + x - 2);
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
