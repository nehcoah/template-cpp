#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] <= s[i + 1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
