/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
 *
 * https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/description/
 *
 * algorithms
 * Hard (47.99%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    29.8K
 * Total Submissions: 62.3K
 * Testcase Example:  '[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]'
 *
 * 给你一棵以 root 为根的 二叉树 ，请你返回 任意 二叉搜索子树的最大键值和。
 *
 * 二叉搜索树的定义如下：
 *
 *
 * 任意节点的左子树中的键值都 小于 此节点的键值。
 * 任意节点的右子树中的键值都 大于 此节点的键值。
 * 任意节点的左子树和右子树都是二叉搜索树。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
 * 输出：20
 * 解释：键值为 3 的子树是和最大的二叉搜索树。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：root = [4,3,null,1,2]
 * 输出：2
 * 解释：键值为 2 的单节点子树是和最大的二叉搜索树。
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [-4,-2,-5]
 * 输出：0
 * 解释：所有节点键值都为负数，和最大的二叉搜索树为空。
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [2,1,3]
 * 输出：6
 *
 *
 * 示例 5：
 *
 *
 * 输入：root = [5,4,8,3,null,6,3]
 * 输出：7
 *
 *
 *
 *
 * 提示：
 *
 *
 * 每棵树有 1 到 40000 个节点。
 * 每个节点的键值在 [-4 * 10^4 , 4 * 10^4] 之间。
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
        int ans = 0;

        tuple<int, int, int> dfs(TreeNode* p) {
            if (p == nullptr) {
                return {INT_MAX, INT_MIN, 0};
            }

            auto [l_min, l_max, lsum] = dfs(p->left);
            auto [r_min, r_max, rsum] = dfs(p->right);

            // 当前节点值小于等于左子树节点最大值或者大于等于右子树节点最小值，说明不是一个二叉搜索树
            if (p->val <= l_max || p->val >= r_min) {
                return {INT_MIN, INT_MAX, 0};
            }
            int sum = p->val + lsum + rsum;
            ans = max(ans, sum);
            return {min(p->val, l_min), max(p->val, r_max), sum};
        }

        int maxSumBST(TreeNode* root) {
            dfs(root);

            return ans;
        }
};

// @lc code=end
