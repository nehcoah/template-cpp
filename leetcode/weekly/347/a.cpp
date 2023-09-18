// https://leetcode.cn/problems/remove-trailing-zeros-from-a-string/

class Solution {
public:
    string removeTrailingZeros(string num) {
        int ans = 0;
        for (int i = num.size() - 1; i >= 0; i--){
            if (num[i] == '0') ans++;
            else break;
        }
        return num.substr(0, num.size() - ans);
    }
};
