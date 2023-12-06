#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    vector<pair<char, int>> L, U;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'b') {
            if (!L.empty()) L.pop_back();
        } else if (s[i] == 'B') {
            if (!U.empty()) U.pop_back();
        } else {
            if (islower(s[i])) L.emplace_back(s[i], i);
            else U.emplace_back(s[i], i);
        }
    }
    int i = 0, j = 0;
    for (; i < L.size() && j < U.size(); ) {
        if (L[i].second < U[j].second) {
            cout << L[i].first;
            i++;
        } else {
            cout << U[j].first;
            j++;
        }
    }
    while (i < L.size()) cout << L[i++].first;
    while (j < U.size()) cout << U[j++].first;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

