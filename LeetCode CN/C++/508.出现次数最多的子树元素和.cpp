/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 *
 * https://leetcode.cn/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (75.61%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    45.8K
 * Total Submissions: 60.7K
 * Testcase Example:  '[5,2,-3]'
 *
 * 给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
 *
 * 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: root = [5,2,-3]
 * 输出: [2,-3,4]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入: root = [5,2,-5]
 * 输出: [2]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 节点数在 [1, 10^4] 范围内
 * -10^5 <= Node.val <= 10^5
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
        unordered_map<int, int> m;
        int                     max_time = 0;

        int dfs(TreeNode* p) {
            if (p == nullptr) {
                return 0;
            }

            int sum = p->val;

            if (p->left) {
                sum += dfs(p->left);
            }

            if (p->right) {
                sum += dfs(p->right);
            }

            m[sum]++;
            max_time = max(max_time, m[sum]);

            return sum;
        }

        vector<int> findFrequentTreeSum(TreeNode* root) {
            vector<int> a;

            dfs(root);

            for (auto& [k, v] : m) {
                if (v == max_time) {
                    a.emplace_back(k);
                }
            }

            return a;
        }
};

// @lc code=end
