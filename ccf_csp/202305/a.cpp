#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < 8; j++) {
            string t;
            cin >> t;
            s += t;
        }
        mp[s]++;
        cout << mp[s] << "\n";
    }

    return 0;
}


