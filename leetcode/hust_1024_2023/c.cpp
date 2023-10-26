class Solution {
public:
    string mathProblem(string s) {
        int pos = s.find('=');
        string l = s.substr(0, pos), r = s.substr(pos + 1);
        // cout << l << " " << r << endl;
        auto get = [](string t) -> pair<int, int> {
            int x = 0, y = 0, n = t.size();
            char op = t[0] == '-' ? '-' : '+';
            for (int i = t[0] == '-' || t[0] == '+'; i < n; i++) {
                if (t[i] == 'x') {
                    x += op == '+' ? 1 : -1;
                    if (i != n - 1) op = t[i + 1];
                    i++;
                } else {
                    int j = i;
                    while (j < n && isdigit(t[j])) j++;
                    if (i == j) {
                        x += op == '+' ? 1 : -1;
                    }
                    int num = stoi(t.substr(i, j - i));
                    if (j != n && t[j] == 'x') {
                        x += op == '+' ? num : -num;
                        if (j < n - 1) op = t[j + 1];
                        i = j + 1;
                    } else {
                        y += op == '+' ? num : -num;
                        if (j != n) op = t[j];
                        i = j;
                    }
                }
            }
            return {x, y};
        };
        
        auto lxy = get(l), rxy = get(r);
        // cout << lxy.first << " " << lxy.second << " " << rxy.first << " " << rxy.second << endl;
        int x = lxy.first - rxy.first, y = rxy.second - lxy.second;
        // cout << x << " " << y << endl;
        
        if (y == 0) {
            if (x == 0) return "Infinite solutions";
            else return "x=0";
        } else {
            if (x == 0 || y % x != 0) return "No solution";
            else {
                string ans = "x=";
                int cur = y / x;
                if (cur < 0) ans.push_back('-');
                ans += to_string(abs(cur));
                return ans;
            }
        }
    }
};
