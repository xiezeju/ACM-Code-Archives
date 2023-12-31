/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode.cn/problems/reorder-list/description/
 *
 * algorithms
 * Medium (65.81%)
 * Likes:    1379
 * Dislikes: 0
 * Total Accepted:    288.3K
 * Total Submissions: 438.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 * 
 * 
 * L0 → L1 → … → Ln - 1 → Ln
 * 
 * 
 * 请将其重新排列后变为：
 * 
 * 
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4]
 * 输出：[1,4,2,3]
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[1,5,2,4,3]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表的长度范围为 [1, 5 * 10^4]
 * 1 <= node.val <= 1000
 * 
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
    void reorderList(ListNode* head) {
        int n = 1;
        ListNode *dummyHead = new ListNode(-1,head);
        ListNode *pre = dummyHead->next;
        while(pre->next) ++n,pre=pre->next;
        if(n<3) return;
        //找到链表后半段然后翻转
        int x = (n+1)/2;
        pre = dummyHead;
        for(int i=1;i<=x;i++) pre = pre->next;
        ListNode *p = pre;
        ListNode *cur = pre->next;
        ListNode *next;
        while(cur->next){
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        
        ListNode *l1 = head;
        ListNode *l2 = p->next;
        p->next = nullptr;
        
        while(l2){
            cur = l1->next;
            l1->next = l2;
            l1 = l1->next;
            l2 = l2->next;
            l1->next = cur;
            l1 = l1->next;
        }

    }
};
// @lc code=end

