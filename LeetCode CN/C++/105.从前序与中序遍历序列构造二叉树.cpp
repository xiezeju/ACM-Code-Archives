/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.22%)
 * Likes:    2108
 * Dislikes: 0
 * Total Accepted:    541K
 * Total Submissions: 759.7K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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
    TreeNode* dfs(vector<int>& pre,vector<int>& in,int left,int right,int n){
        if(left>right) return nullptr;
        if(left==right){
            return new TreeNode(in[left]);
        }
        return new TreeNode(pre[n],dfs(pre,in,left,idx[pre[n]]-1,n+1),dfs(pre,in,idx[pre[n]]+1,right,n+1+idx[pre[n]]-left));
    }


    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<pre.size();i++)idx[in[i]] = i;
        return dfs(pre,in,0,pre.size()-1,0);
    }
};

class Solution {
public:
    unordered_map<int,int> idx;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd){
        if(preStart>preEnd){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inOrderRoot = idx[preorder[preStart]];
        int subLTree = inOrderRoot - inStart;
        root->left = dfs(preorder,inorder,preStart+1,preStart+subLTree,inStart,inOrderRoot-1);
        root->right = dfs(preorder,inorder,preStart+subLTree+1,preEnd,inOrderRoot+1,inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<inorder.size();i++){
            idx[inorder[i]] = i;
        }
        return dfs(preorder,inorder,0,n-1,0,n-1);
    }  
};


// @lc code=end

