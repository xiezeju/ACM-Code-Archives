/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
 *
 * https://leetcode.cn/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (70.26%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    84.1K
 * Total Submissions: 119.8K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
 * 
 * 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[1,1,1,1,1,null,1]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[2,2,2,5,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定树的节点数范围是 [1, 100]。
 * 每个节点的值都是整数，范围为 [0, 99] 。
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int val;
    bool ok = true;
    void dfs(TreeNode* p){
        if(p==nullptr){
            return;
        }
        if(p->val!=val){
            ok = false;
            return;
        }
        dfs(p->left);
        dfs(p->right);
    }

    bool isUnivalTree(TreeNode* root) {
        val = root->val;
        dfs(root);
        return ok;
    }
};
// @lc code=end

