#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if (count(s.begin(), s.end(), '1') == 1 && count(s.begin(), s.end(), '2') == 2 && count(s.begin(), s.end(), '3') == 3) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
