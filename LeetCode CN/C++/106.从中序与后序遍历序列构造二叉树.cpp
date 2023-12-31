/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (71.88%)
 * Likes:    1119
 * Dislikes: 0
 * Total Accepted:    313.7K
 * Total Submissions: 436.5K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder
 * 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * 输出：[3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：inorder = [-1], postorder = [-1]
 * 输出：[-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder 和 postorder 都由 不同 的值组成
 * postorder 中每一个值都在 inorder 中
 * inorder 保证是树的中序遍历
 * postorder 保证是树的后序遍历
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
/*
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        int rootValue = postorder[postEnd];
        TreeNode* root = new TreeNode(rootValue);

        int inRootIndex = inStart;
        while (inorder[inRootIndex] != rootValue) {
            inRootIndex++;
        }

        int leftSubtreeSize = inRootIndex - inStart;
        int rightSubtreeSize = inEnd - inRootIndex;

        root->left = buildTreeHelper(inorder, postorder, inStart, inRootIndex - 1, postStart, postStart + leftSubtreeSize - 1);
        root->right = buildTreeHelper(inorder, postorder, inRootIndex + 1, inEnd, postEnd - rightSubtreeSize, postEnd - 1);

        return root;
    }
};
*/
class Solution {
public:
    unordered_map<int,int> idx;

    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder,int inoreder_left,int inorder_right,int postorder_left,int postorder_right){
        if(inoreder_left>inorder_right||postorder_left>postorder_right){
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postorder_right]);
        int inOrderRoot = idx[postorder[postorder_right]];
        int subLTree = inOrderRoot - inoreder_left;
        int subRTree = inorder_right - inOrderRoot;
        
        root->left = dfs(inorder,postorder,inoreder_left,inOrderRoot-1,postorder_left,postorder_left+subLTree-1);
        root->right = dfs(inorder,postorder,inOrderRoot+1,inorder_right,postorder_right-subRTree,postorder_right-1);
        
        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            idx[inorder[i]] = i;
        }
        return dfs(inorder,postorder,0,n-1,0,n-1);
    }
};
// @lc code=end

