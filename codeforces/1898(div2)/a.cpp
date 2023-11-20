#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (char c : s) {
        if (c == 'A') a++;
        else b++;
    }
    if (b == k) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0, A = 0, B = 0; i < s.size(); i++) {
        if (s[i] == 'A') A++;
        else B++;
        if (b > k) {
            if (b - B == k) {
                cout << 1 << endl;
                cout << i + 1 << " A" << endl;
                return;
            }
        } else {
            if (b + A == k) {
                cout << 1 << endl;
                cout << i + 1 << " B" << endl;
                return;
            }
        }
    }
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


