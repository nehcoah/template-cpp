#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s;
    cin >> s;

    auto pos = s.find("ABC");
    if (pos == string::npos) cout << -1 << endl;
    else cout << pos + 1 << endl;

    return 0;
}
