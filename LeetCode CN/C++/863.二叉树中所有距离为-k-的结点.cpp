/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 *
 * https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (61.37%)
 * Likes:    658
 * Dislikes: 0
 * Total Accepted:    54.8K
 * Total Submissions: 89.3K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * 给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 k 。
 * 
 * 返回到目标结点 target 距离为 k 的所有结点的值的列表。 答案可以以 任何顺序 返回。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
 * 输出：[7,4,1]
 * 解释：所求结点为与目标结点（值为 5）距离为 2 的结点，值分别为 7，4，以及 1
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: root = [1], target = 1, k = 3
 * 输出: []
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数在 [1, 500] 范围内
 * 0 <= Node.val <= 500
 * Node.val 中所有值 不同
 * 目标结点 target 是树上的结点。
 * 0 <= k <= 1000
 * 
 * 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,TreeNode*> m;
    void findFather(TreeNode* p,TreeNode* pre){
        if(p==nullptr){
            return;
        }
        m[p->val] = pre;
        findFather(p->left,p);
        findFather(p->right,p);
    }

    void dfs(TreeNode *p,TreeNode *from, int k,int deep,vector<int>& a){
        if(p==nullptr){
            return;
        }
        if(deep==k){
            a.push_back(p->val);
            return;
        }
        if(p->left!=from){
            dfs(p->left,p,k,deep+1,a);
        }
        if(p->right!=from){
            dfs(p->right,p,k,deep+1,a);
        }
        if(m[p->val]!=from){
            dfs(m[p->val],p,k,deep+1,a);
        }
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return vector<int>{target->val};
        vector<int> a;
        findFather(root,nullptr);
        dfs(target,target,k,0,a);
        return a;
    }
};
// @lc code=end

