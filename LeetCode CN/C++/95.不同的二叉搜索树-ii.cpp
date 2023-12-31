/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode.cn/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (73.61%)
 * Likes:    1498
 * Dislikes: 0
 * Total Accepted:    178K
 * Total Submissions: 241.8K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n
 * 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        vector<TreeNode*> build(int l, int r) {

            if (l > r) {
                return {nullptr};
            }

            vector<TreeNode*> a;

            for (int i = l; i <= r; i++) {
                vector<TreeNode*> left = build(l, i - 1);
                vector<TreeNode*> right = build(i + 1, r);
                for (auto& ltree : left) {
                    for (auto& rtree : right) {
                        TreeNode* root = new TreeNode(i);
                        root->left = ltree;
                        root->right = rtree;
                        a.emplace_back(root);
                    }
                }
            }

            return a;
        }

        vector<TreeNode*> generateTrees(int n) { return build(1, n); }
};

// @lc code=end
