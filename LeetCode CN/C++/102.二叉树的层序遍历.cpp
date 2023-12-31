/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (66.02%)
 * Likes:    1825
 * Dislikes: 0
 * Total Accepted:    894.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
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
    

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> a;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto u = q.front();q.pop();
            TreeNode* node = u.first;
            int idx = u.second;
            int size = a.size();
            if(node==nullptr){
                continue;
            }
            if(idx > size-1){
               a.push_back(vector<int>{node->val}); 
            }
            else{
                a[idx].push_back(node->val);
            }
            q.push({node->left,idx+1});
            q.push({node->right,idx+1});
        }
        return a;
    }
};
// @lc code=end

