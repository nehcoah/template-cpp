#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    bool good = isupper(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (!islower(s[i])) good = false;
    }
    cout << (good ? "Yes\n" : "No\n");

    return 0;
}
