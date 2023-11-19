#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        if (i < s.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}


