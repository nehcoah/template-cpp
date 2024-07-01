#include "bits/stdc++.h"
using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    for (int l = 1; l < s.size(); l++) {
        for (int i = 0; i < l; i++) {
            string cur;
            for (int j = i; j < s.size(); j += l) {
                cur += s[j];
            }
            if (cur == t) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";

    return 0;
}
