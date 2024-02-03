#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '.') {
            cout << s.substr(i + 1) << endl;
            return 0;
        }
    }

    return 0;
}
