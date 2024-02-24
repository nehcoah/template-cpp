#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    array<char, 26> change{};
    iota(change.begin(), change.end(), 'a');
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char a, b;
        cin >> a >> b;
        for (int j = 0; j < 26; j++) {
            if (change[j] == a) change[j] = b;
        }
    }
    for (char c : s) {
        cout << change[c - 'a'];
    }
    cout << "\n";

    return 0;
}
