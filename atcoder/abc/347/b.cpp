#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    unordered_set<string> st;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            st.insert(s.substr(i, j - i + 1));
        }
    }
    cout << st.size() << endl;

    return 0;
}
