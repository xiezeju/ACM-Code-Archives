/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
 *
 * https://leetcode.cn/problems/search-in-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (77.72%)
 * Likes:    446
 * Dislikes: 0
 * Total Accepted:    287.2K
 * Total Submissions: 369.3K
 * Testcase Example:  '[4,2,7,1,3]\n2'
 *
 * 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
 *
 * 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。
 * 如果节点不存在，则返回 null 。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入：root = [4,2,7,1,3], val = 2
 * 输出：[2,1,3]
 *
 *
 * 示例 2:
 *
 *
 * 输入：root = [4,2,7,1,3], val = 5
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 数中节点数在 [1, 5000] 范围内
 * 1 <= Node.val <= 10^7
 * root 是二叉搜索树
 * 1 <= val <= 10^7
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        TreeNode* ans;

        void dfs(TreeNode* p, int val) {
            if (p == nullptr) {
                return;
            }

            if (p->val == val) {
                ans = p;
                return;
            }

            if (val < p->val) {
                dfs(p->left, val);
            }
            if (val > p->val) {
                dfs(p->right, val);
            }
        }

        TreeNode* searchBST(TreeNode* root, int val) {
            dfs(root, val);
            return ans;
        }
};

// @lc code=end
