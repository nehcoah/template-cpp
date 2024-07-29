#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == "sweet" && s[i + 1] == "sweet") {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}
