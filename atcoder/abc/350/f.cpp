//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> match(n), stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push_back(i);
        else if (s[i] == ')') {
            match[i] = stk.back();
            match[stk.back()] = i;
            stk.pop_back();
        }
    }
    string ans;
    int d = 1, p = 0;
    while (p < n) {
        if (s[p] == '(' || s[p] == ')') {
            p = match[p];
            d = -d;
        } else {
            char c = s[p];
            if (d == -1) {
                if (islower(c)) c = toupper(c);
                else c = tolower(c);
            }
            ans += c;
        }
        p += d;
    }
    cout << ans << endl;

    return 0;
}
