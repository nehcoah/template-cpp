#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, print_cnt = 0;
    cin >> n;
    deque<int> dq;
    vector<int> data;

    unordered_map<char, int> mp {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},
                                 {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
                                 {'8', 8}, {'9', 9}, {'a', 10}, {'b', 11},
                                 {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15}};
    auto get = [&](char a, char b) {
        return mp[a] * 16 + mp[b];
    };

    auto append = [&](int o, int l) {
        for (int i = dq.size() - o, cnt = 0; cnt < l; i++, cnt++) dq.push_back(dq[i]);
    };

    auto print = [&](int x) {
        int c = x / 16;
        cout << (c < 10 ? char(c + '0') : char('a' + c - 10));
        c = x % 16;
        cout << (c < 10 ? char(c + '0') : char('a' + c - 10));
        if (++print_cnt == 8) cout << "\n", print_cnt = 0;
    };

    for (int i = 0; i < (n + 7) / 8; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j += 2) {
            data.push_back(get(s[j], s[j + 1]));
        }
    }

    int i = 0;
    while ((data[i] >> 7) & 1) i++;
    i++;
    while (i < n) {
        int head = data[i];
        int type = head & 3;
        head >>= 2;
        if (type == 0) {
            if (head <= 59) {
                for (int j = 0; j <= head; j++) {
                    dq.push_back(data[i + j + 1]);
                }
                i += head + 2;
            } else {
                int len = 0;
                for (int j = 0; j < head - 59; j++) len += data[i + j + 1] * int(pow(256, j));
                i += head - 59;
                for (int j = 0; j <= len; j++) dq.push_back(data[i + j + 1]);
                i += len + 2;
            }
        } else if (type == 1) {
            int l = (head & 7) + 4;
            int o = (head >> 3) * 256 + data[i + 1];
            append(o, l);
            i += 2;
        } else {
            int l = head + 1;
            int o = data[i + 1] + data[i + 2] * 256;
            append(o, l);
            i += 3;
        }
        while (dq.size() > 65536) {
            print(dq.front());
            dq.pop_front();
        }
    }

    while (!dq.empty()) {
        print(dq.front());
        dq.pop_front();
    }

    return 0;
}


