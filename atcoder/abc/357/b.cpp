#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s) {
        if (isupper(c)) cnt += 1;
    }
    if (cnt * 2 < s.size()) {
        for (char &c : s) {
            if (isupper(c)) c = tolower(c);
        }
    } else {
        for (char &c : s) {
            if (islower(c)) c = toupper(c);
        }
    }
    cout << s << endl;

    return 0;
}

