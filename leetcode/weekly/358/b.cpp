// 2816
// https://leetcode.cn/problems/double-a-number-represented-as-a-linked-list/
// linkedlist

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        auto dfs = [&](auto self, auto cur) -> bool {
            if (cur) cur->val = cur->val * 2 + self(self, cur->next);
            if (cur == nullptr) return false;
            bool carry = false;
            if (cur->val > 9) cur->val -= 10, carry = 1;
            return carry;
        };
        if (dfs(dfs, head)) head = new ListNode(1, head);
        return head;
    }
};
