// https://leetcode.cn/problems/minimum-additions-to-make-valid-string/

class Solution {
public:
    int addMinimum(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n;){
            if (s[i] == 'a'){
                if (i == n - 1){
                    ans += 2;
                    break;
                } else if(s[i + 1] == 'a') {
                    ans += 2;
                    i += 1;
                } else if (i < n - 2 && s[i + 1] == 'b' && s[i + 2] == 'c') i += 3;
                else if (s[i + 1] == 'b' || s[i + 1] == 'c') {
                    ans += 1;
                    i += 2;
                }
            } else if (s[i] == 'b'){
                ans += 1; //a
                if (i == n - 1){
                    ans += 1;
                    break;
                } else if(s[i + 1] != 'c'){
                    ans += 1;
                    i += 1;
                } else i += 2;
            } else {
                ans += 2;
                i += 1;
            }
        }
        return ans;
    }
};
