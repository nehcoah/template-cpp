#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int h = stoi(s.substr(0, 2));
    int p = 0;
    if (h == 0) {
        s[0] = '1', s[1] = '2';
    } else if (h >= 12) {
        p = 1;
        if (h > 12) {
            h -= 12;
            s = (h < 10 ? "0" : "") + to_string(h) + s.substr(2);
        }
    }
    cout << s << " " << (p ? "PM" : "AM") << endl;
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
