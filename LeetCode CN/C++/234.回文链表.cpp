/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (53.60%)
 * Likes:    1821
 * Dislikes: 0
 * Total Accepted:    662.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true
 * ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,2,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 *
 *
 *
 *
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 *
 */

// @lc code=start
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
        ListNode* pre;

        bool dfs(ListNode* cur) {
            // 尾指针出界，返回链表尾部
            if (cur == nullptr)
                return true;
            // 递归链中出现了失败比较，就直接返回false无需继续比较了
            if (!dfs(cur->next)) {
                return false;
            }
            // 进行，比较失败直接返回false
            if (pre->val != cur->val) {
                return false;
            }
            // 否则继续后面的比较
            pre = pre->next;
            // 比较成功，尾指针返回上一层
            return true;
        }

        bool isPalindrome(ListNode* head) {
            pre = head;
            return dfs(head);
        }
};

// @lc code=end
