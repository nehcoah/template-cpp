#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    bool A = false, B = false;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            int a = 0, b = 0, cnta = 0, cntb = 0, i = 0;
            for (; i < n; i++) {
                (s[i] == 'A' ? cnta : cntb) += 1;
                if (cnta == x) {
                    a++, cnta = 0, cntb = 0;
                    if (a == y) {
                        if (i == n - 1) A = true;
                        else break;
                    }
                }
                if (cntb == x) {
                    b++, cnta = 0, cntb = 0;
                    if (b == y) {
                        if (i == n - 1) B = true;
                        else break;
                    }
                }
            }
        }
    }
    if (A && B) cout << "?" << endl;
    else if (A) cout << "A" << endl;
    else if (B) cout << "B" << endl;
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

