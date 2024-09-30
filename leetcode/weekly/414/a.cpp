class Solution {
public:
    string convertDateToBinary(string date) {
        stringstream ss(date);
        string s, ans;
        while (getline(ss, s, '-')) {
            int x = stoi(s);
            string cur;
            while (x) {
                cur += char('0' + x % 2);
                x /= 2;
            }
            reverse(cur.begin(), cur.end());
            ans += cur + "-";
        }
        ans.pop_back();
        return ans;
    }
};
