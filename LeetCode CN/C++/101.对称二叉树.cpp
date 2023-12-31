/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (59.21%)
 * Likes:    2564
 * Dislikes: 0
 * Total Accepted:    911.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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
    
    void rotation(TreeNode* p){
        if(p==nullptr){
            return;
        }
        swap(p->left,p->right);
        rotation(p->left);
        rotation(p->right);
    }

    bool dfs(TreeNode* p, TreeNode *q){
        if(p==nullptr&&q==nullptr){
            return true;
        }
        else if(p==nullptr||q==nullptr){
            return false;
        }
        else if(p->val!=q->val){
            return false;
        }
        return dfs(p->left,q->left) && dfs(p->right,q->right);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        rotation(root->left);
        return dfs(root->left,root->right);
    }
};
// @lc code=end

