#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = n; i < 1000; i++) {
        string s = to_string(i);
        if ((s[0] - '0') * (s[1] - '0') == s[2] - '0') {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}

