#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<char> stk;
    for (char c : s) {
        stk.push_back(c);
        if (stk.size() > 2) {
            int n = stk.size();
            if (stk[n - 3] == 'A' && stk[n - 2] == 'B' && stk[n - 1] == 'C') {
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
            }
        }
    }
    for (char c : stk) cout << c;
    cout << endl;

    return 0;
}

