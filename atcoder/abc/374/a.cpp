#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    
    if (s.substr(s.size() - 3) == "san") {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}

