/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (66.37%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    131.8K
 * Total Submissions: 198.6K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 * 
 * 
 * 
 * 示例1：
 * 
 * 
 * 
 * 
 * 输入: root = [1,3,2,5,3,null,9]
 * 输出: [1,3,9]
 * 
 * 
 * 示例2：
 * 
 * 
 * 输入: root = [1,2,3]
 * 输出: [1,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 二叉树的节点个数的范围是 [0,10^4]
 * -2^31 <= Node.val <= 2^31 - 1
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* p,int deep,vector<int>& a){
        if(p==nullptr){
            return;
        }
        if(a.size()<=deep){
            a.push_back(p->val);
        }
        else{
            a[deep] = max(a[deep],p->val);
        }
        dfs(p->left,deep+1,a);
        dfs(p->right,deep+1,a);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> a;
        dfs(root,0,a);
        return a;
    }
};
// @lc code=end

