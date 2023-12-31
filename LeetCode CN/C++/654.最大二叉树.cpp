/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 *
 * https://leetcode.cn/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (82.25%)
 * Likes:    746
 * Dislikes: 0
 * Total Accepted:    221.8K
 * Total Submissions: 270.1K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums
 * 递归地构建:
 *
 *
 * 创建一个根节点，其值为 nums 中的最大值。
 * 递归地在最大值 左边 的 子数组前缀上 构建左子树。
 * 递归地在最大值 右边 的 子数组后缀上 构建右子树。
 *
 *
 * 返回 nums 构建的 最大二叉树 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,2,1,6,0,5]
 * 输出：[6,3,5,null,2,0,null,null,1]
 * 解释：递归调用如下所示：
 * - [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
 * ⁠   - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是
 * [2,1] 。 ⁠       - 空数组，无子节点。 ⁠       - [2,1]
 * 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。 ⁠ -
 * 空数组，无子节点。 ⁠           -
 * 只有一个元素，所以子节点是一个值为 1 的节点。
 * ⁠   - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是
 * [] 。 ⁠       - 只有一个元素，所以子节点是一个值为 0
 * 的节点。 ⁠       - 空数组，无子节点。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,2,1]
 * 输出：[3,null,2,null,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * nums 中的所有整数 互不相同
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
        TreeNode* build(vector<int>& nums, TreeNode* p, int l, int r) {
            if (l > r) {
                return nullptr;
            }

            if (l == r) {
                return new TreeNode(nums[l]);
            }

            int max_num = 0, index = 0;

            for (int i = l; i <= r; i++) {
                if (nums[i] > max_num) {
                    max_num = nums[i];
                    index = i;
                }
            }

            return new TreeNode(max_num, build(nums, p, l, index - 1),
                                build(nums, p, index + 1, r));
        }

        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            int n = nums.size();

            TreeNode* root = build(nums, nullptr, 0, n - 1);

            return root;
        }
};

// @lc code=end
