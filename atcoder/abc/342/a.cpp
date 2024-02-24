#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if (s[0] == s[1]) {
        char c = s[0];
        for (int i = 2; i < s.size(); i++) {
            if (c != s[i]) {
                cout << i + 1 << endl;
                return 0;
            }
        }
    } else {
        if (s[2] == s[0]) cout << 2 << endl;
        else cout << 1 << endl;
    }

    return 0;
}
