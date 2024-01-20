#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int i = 0, n = s.size();
    while (i < n && s[i] == 'A') i++;
    while (i < n && s[i] == 'B') i++;
    while (i < n && s[i] == 'C') i++;
    cout << (i == n ? "Yes\n" : "No\n");

    return 0;
}
