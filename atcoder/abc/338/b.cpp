#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    array<int, 26> cnt{};
    for (char c : s) {
        cnt[c - 'a']++;
    }
    int mx = *max_element(cnt.begin(), cnt.end());
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == mx) {
            cout << char('a' + i) << endl;
            return 0;
        }
    }

    return 0;
}
