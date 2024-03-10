#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int cnt = 0;
    for (char c : s) {
        if (c == '|') cnt += 1;
        else {
            if (cnt != 1) cout << c;
        }
    }
    cout << endl;

    return 0;
}
