#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t = "wbwbwwbwbwbw";
    int w, b;
    cin >> w >> b;

    for (int i = 0; i < 20; i++) {
        t += t;
    }
    int cntw = 0, cntb = 0;
    for (int i = 0; i < w + b; i++) {
        (t[i] == 'w' ? cntw : cntb) += 1;
    }
    if (cntw == w && cntb == b) {
        cout << "Yes\n";
        return 0;
    }
    for (int i = w + b; i < t.size(); i++) {
        (t[i] == 'w' ? cntw : cntb) += 1;
        (t[i - w - b] == 'w' ? cntw : cntb) -= 1;
        if (cntw == w && cntb == b) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

    return 0;
}
