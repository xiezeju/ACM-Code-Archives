/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode.cn/problems/partition-list/description/
 *
 * algorithms
 * Medium (64.32%)
 * Likes:    760
 * Dislikes: 0
 * Total Accepted:    238K
 * Total Submissions: 370K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
 * 
 * 你应当 保留 两个分区中每个节点的初始相对位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,4,3,2,5,2], x = 3
 * 输出：[1,2,2,4,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [2,1], x = 2
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 200] 内
 * -100 
 * -200 
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
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next) return head;
        ListNode *dummyHead = new ListNode(-300,head);
        ListNode *pre = dummyHead;
        ListNode *cur = pre->next;
        ListNode *X=nullptr, *next=nullptr;
        while(pre->next){
            if(pre->next->val>=x){
                X = pre->next;
                cur = pre->next;
                break;
            } else pre = pre->next;
        }
        if(X==nullptr) return dummyHead->next;
        while(cur->next){
            next = cur->next;
            if(next->val<x){
                pre->next = next;
                cur->next = next->next;
                next->next = X;
                pre = next;
            }
            else cur = cur->next;
        }
        return dummyHead->next;
    }
};
// @lc code=end

