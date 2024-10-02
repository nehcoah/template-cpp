#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    while (s.back() == '0') {
        s.pop_back();
    }
    if (s.back() == '.') s.pop_back();
    cout << s << endl;

    return 0;
}

