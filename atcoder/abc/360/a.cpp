#include "bits/stdc++.h"
using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int r = find(s.begin(), s.end(), 'R') - s.begin();
    int m = find(s.begin(), s.end(), 'M') - s.begin();

    cout << (r < m ? "Yes\n" : "No\n");

    return 0;
}
