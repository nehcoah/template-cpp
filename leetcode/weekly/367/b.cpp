class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans;
        int n = s.size(), cnt = 0, i = 0, j = 0;
        for (; i < n; i++) {
            if (s[i] == '1') cnt++;
            if (cnt == k) break;
        }
        while (s[j] == '0') j++;
        if (cnt != k) return "";
        
        ans = s.substr(j, i - j + 1);
        i++;
        for (; i < n; i++) {
            if (s[i] == '1') cnt++;
            while (j < i && cnt != k) if (s[j++] == '1') cnt--;
            while (s[j] == '0') j++;
            string t = s.substr(j, i - j + 1);
            if (t.size() < ans.size()) ans = t;
            else if (t.size() == ans.size()) ans = min(ans, t);
        }
        return ans;
    }
};
