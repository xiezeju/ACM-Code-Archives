/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Medium (72.80%)
 * Likes:    748
 * Dislikes: 0
 * Total Accepted:    296.1K
 * Total Submissions: 406.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。
 * （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[15,7],[9,20],[3]]
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> ans;
            if (root == nullptr) {
                return {};
            }

            queue<TreeNode*> q;
            q.emplace(root);

            while (!q.empty()) {
                int t = q.size();

                vector<int> a;
                while (t--) {
                    TreeNode* u = q.front();
                    q.pop();
                    a.emplace_back(u->val);
                    if (u->left) {
                        q.emplace(u->left);
                    }
                    if (u->right) {
                        q.emplace(u->right);
                    }
                }
                ans.emplace_back(a);
            }

            reverse(ans.begin(), ans.end());

            return ans;
        }
};

// @lc code=end
