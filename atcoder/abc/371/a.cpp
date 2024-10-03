#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char ab, ac, bc;
    cin >> ab >> ac >> bc;

    vector<int> a(3);
    if (ab == '>') a[1] += 1;
    else a[0] += 1;
    if (ac == '>') a[2] += 1;
    else a[0] += 1;
    if (bc == '>') a[2] += 1;
    else a[1] += 1;

    cout << char(find(a.begin(), a.end(), 1) - a.begin() + 'A') << endl;

    return 0;
}

