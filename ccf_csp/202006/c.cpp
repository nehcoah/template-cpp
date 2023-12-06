#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> str;
    string t;
    int n; cin >> n;

    getline(cin, t);
    while (getline(cin, t)) {
        str.push_back(t);
    }

    /*
     * 段落：
     * 1. 去掉首尾的空格
     * 2. 段落包含多行文本，各行之间用一个空格连接
     * 3. 渲染时与之前的段落或项目列表空出一行的间距
     * 4. 超出终端宽度，从下一行开始继续渲染，剩下的文本以空格开头，则删除空格
     *
     * 项目：
     * 1. 第一行必须以 "* " 开头，其余行以 "  " 开头
     * 2. 项目列表由连续的一个或多个项目组成，各个项目之间没有空白行或不是两个空格开头的行
     * 3. 两个项目列表之间没有空白行或开头不是两个空格的行，应被视为一个项目列表
     * 4. 渲染时，与之前的段落或项目空出一行间距
     * 5. 渲染项目时，宽度-3
     * 6. 特别的！一行只有 "* " 时，不用空一行
     * 
     * 解释：多个"* "之间不用空行，只有段落和项目之间切换时需要空行
     * 解释："* "之后的"  "被视为和之前的"* "在同一行渲染，每次出现"* "就换行
     */

    auto check = [&](string &s, int w) -> int {
        int ans = 1, pos = 0;
        for (int i = 0; i < s.size(); ) {
            pos++, i++;
            if (i == s.size()) break;
            if (pos == n + w) {
                pos = 0, ans++;
                while (i < s.size() && s[i] == ' ') i++;
            }
        }
        return ans;
    };

    while (true) {
        if (str.back().empty()) str.pop_back();
        else if (count(str.back().begin(), str.back().end(), ' ') == str.back().size()) str.pop_back();
        else break;
    }

    int ans = 0, item = 0, i = 0;
    string cur;
    while (i < str.size() && count(str[i].begin(), str[i].end(), ' ') == str[i].size()) i++;
    for (; i < str.size(); i++) {
        if (count(str[i].begin(), str[i].end(), ' ') == str[i].size()) {
            ans++;
            ans += check(cur, item == 1 ? -3 : 0);
            cur.clear();
            item = 0;
            while (i + 1 < str.size()) {
                if (count(str[i + 1].begin(), str[i + 1].end(), ' ') == str[i + 1].size()) i++;
                else break;
            }
            continue;
        }
        if (str[i][0] == '*' && str[i][1] == ' ') {
            if (!cur.empty() && item == 0) {
                ans++;
                ans += check(cur, 0);
                cur.clear();
            }
            if (item == 1) {
                ans += check(cur, -3);
                cur.clear();
            }
            item = 1;
            str[i] = str[i].substr(2);
        } else if (item == 1) {
            if (str[i][0] == ' ' && str[i][1] == ' ') str[i] = str[i].substr(2);
            else {
                ans++;
                ans += check(cur, -3);
                cur.clear();
                item = 0;
            }
        }
        int l = 0, r = str[i].size() - 1;
        while (l < r && str[i][l] == ' ') l++;
        while (l < r && str[i][r] == ' ') r--;
        str[i] = str[i].substr(l, r - l + 1);
        if (!cur.empty() && !str[i].empty()) cur += " ";
        cur += str[i];
    }
    
    ans += check(cur, item == 1 ? -3 : 0);
    cout << ans << endl;

    return 0;
}

