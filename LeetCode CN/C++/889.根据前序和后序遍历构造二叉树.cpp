/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (67.82%)
 * Likes:    327
 * Dislikes: 0
 * Total Accepted:    41.6K
 * Total Submissions: 61.4K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * 给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder
 * 是同一棵树的后序遍历，重构并返回二叉树。
 * 
 * 如果存在多个答案，您可以返回其中 任何 一个。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
 * 输出：[1,2,3,4,5,6,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: preorder = [1], postorder = [1]
 * 输出: [1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= preorder.length <= 30
 * 1 <= preorder[i] <= preorder.length
 * preorder 中所有值都 不同
 * postorder.length == preorder.length
 * 1 <= postorder[i] <= postorder.length
 * postorder 中所有值都 不同
 * 保证 preorder 和 postorder 是同一棵二叉树的前序遍历和后序遍历
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
    unordered_map<int,int> idx;

    TreeNode* dfs(vector<int>& preorder, vector<int>& postorder,int preorder_left,int preorder_right,int postorder_left,int postorder_right){
        if(preorder_left>preorder_right||postorder_left>postorder_right){
            return nullptr;
        }
        int rootValue = preorder[preorder_left];
        TreeNode* root = new TreeNode(rootValue);
        if(preorder_left==preorder_right){
            return root;
        }
        
        int lSubTreeNum = idx[preorder[preorder_left+1]] - postorder_left + 1;
        root->left = dfs(preorder, postorder, preorder_left + 1, preorder_left + lSubTreeNum, postorder_left, postorder_left + lSubTreeNum - 1);
        root->right = dfs(preorder, postorder, preorder_left + lSubTreeNum + 1, preorder_right, postorder_left + lSubTreeNum, postorder_right - 1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++){
            idx[postorder[i]] = i;
        }
        return dfs(preorder,postorder,0,n-1,0,n-1);

    }
};
// @lc code=end

