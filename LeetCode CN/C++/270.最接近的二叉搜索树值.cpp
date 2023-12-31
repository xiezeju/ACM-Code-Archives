/*
 * @lc app=leetcode.cn id=270 lang=cpp
 *
 * [270] 最接近的二叉搜索树值
 *
 * https://leetcode.cn/problems/closest-binary-search-tree-value/description/
 *
 * algorithms
 * Easy (55.28%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    19.5K
 * Total Submissions: 35.5K
 * Testcase Example:  '[4,2,5,1,3]\n3.714286'
 *
 * 给你二叉搜索树的根节点 root 和一个目标值 target
 * ，请在该二叉搜索树中找到最接近目标值 target
 * 的数值。如果有多个答案，返回最小的那个。
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [4,2,5,1,3], target = 3.714286
 * 输出：4
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1], target = 4.428571
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 10^4] 内
 * 0 <= Node.val <= 10^9
 * -10^9 <= target <= 10^9
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
        int    ans = INT_MAX;
        double dis = 1e9 + 7;

        void dfs(TreeNode* p, double target) {
            if (p == nullptr) {
                return;
            }

            dfs(p->left, target);

            if (abs(p->val - target) < dis) {
                dis = abs(p->val - target);
                ans = p->val;
            }

            dfs(p->right, target);
        }

        int closestValue(TreeNode* root, double target) {

            dfs(root, target);
            return ans;
        }
};

// @lc code=end
