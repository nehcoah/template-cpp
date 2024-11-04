class Solution {
public:
    bool isBalanced(string num) {
        int odd = 0, even = 0;
        for (int i = 0; i < num.size(); i++) {
            (i % 2 == 0 ? odd : even) += num[i] - '0';
        }
        return odd == even;
    }
};
