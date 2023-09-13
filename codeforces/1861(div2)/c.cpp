#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    string s;
    cin >> s;
    int mx_sorted = 0, mn_unsorted = 0, cur = 0;
    for (char c : s) {
        if (c == '+') cur++;
        else if (c == '-') {
            cur--;
            mx_sorted = min(mx_sorted, cur);
            if (mn_unsorted > cur) mn_unsorted = 0;
        } else if (c == '1') mx_sorted = cur;
        else {
            if (cur < 2) {
                cout << "NO" << endl;
                return;
            }
            if (mn_unsorted == 0 || mn_unsorted > cur) mn_unsorted = cur;
        }
        if (mn_unsorted <= mx_sorted && mn_unsorted != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
