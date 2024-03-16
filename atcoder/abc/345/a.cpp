#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    if (s[0] == '<' && s.back() == '>' && count(s.begin() + 1, s.end() - 1, '=') == s.size() - 2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
