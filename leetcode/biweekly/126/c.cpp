class Solution {
public:
    string minimizeStringValue(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
        vector<int> cnt(26);
        for (char c : s) {
            if (c != '?') cnt[c - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++) {
            pq.push({cnt[i], char(i + 'a')});
        }
        int k = s.size() - accumulate(cnt.begin(), cnt.end(), 0);
        string ans;
        while (k--) {
            auto [x, c] = pq.top(); pq.pop();
            ans += c;
            pq.push({x + 1, c});
        }
        sort(ans.begin(), ans.end());
        int i = 0;
        for (char &c : s) {
            if (c == '?') c = ans[i++];
        }
        return s;
    }
};
