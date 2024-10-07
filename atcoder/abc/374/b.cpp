#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << 0 << endl;
        return 0;
    }

    int i = 0;
    while (i < min(s.size(), t.size()) && s[i] == t[i]) {
        i += 1;
    }
    cout << i + 1 << endl;

    return 0;
}

