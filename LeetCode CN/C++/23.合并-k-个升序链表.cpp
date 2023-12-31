/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 *
 * https://leetcode.cn/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (58.46%)
 * Likes:    2659
 * Dislikes: 0
 * Total Accepted:    713.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
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

//暴力解法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& l) {
        ListNode *head = nullptr, *tail = nullptr;
        vector<ListNode*> list;
        for(auto it=l.begin();it!=l.end();++it)
            if(*it) list.push_back(*it);

        while(list.size()){
            int n = INT_MAX;
            int x = 1000;
            for(int i=0;i<list.size();i++){
                if(list[i]&&list[i]->val<=n){
                    n = list[i]->val;
                    x = i;
                }
            }

            if(list[x]->next) list[x] = list[x]->next;
            else list.erase(list.begin()+x);
            
            if(!head)
                head = tail = new ListNode(n);
            else{
                tail->next = new ListNode(n);
                tail = tail->next;
            }
            
        }


        return head;
    }
};

//优先队列解法
class Solution {
public:
    struct cmp{
        bool operator()(ListNode* a, ListNode *b){
            return a->val > b->val;
        }
    };

    priority_queue<ListNode*,vector<ListNode*>,cmp> q;

    ListNode* mergeKLists(vector<ListNode*>& list) {
        for(auto i:list)
            if(i) q.push(i);
        ListNode *dummyHead = new ListNode();
        ListNode *tail = dummyHead;
        while(!q.empty()){
            ListNode *u = q.top();
            q.pop();
            tail->next = u;
            tail = tail->next;
            if(u->next) q.push(u->next);
        }
        return dummyHead->next;
    }
};


// @lc code=end

