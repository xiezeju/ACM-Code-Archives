/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode.cn/problems/subsets/description/
 *
 * algorithms
 * Medium (81.15%)
 * Likes:    2193
 * Dislikes: 0
 * Total Accepted:    701.1K
 * Total Submissions: 864.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同
 * 。返回该数组所有可能的子集（幂集）。
 *
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10
 * nums 中的所有元素 互不相同
 *
 *
 */

// @lc code=start
class Solution {
    public:
        vector<vector<int>> ans;

        vector<int> a;

        void dfs(vector<int>& nums, int x, int n) {

            if (x == n) {
                ans.emplace_back(a);
                return;
            }

            a.emplace_back(nums[x]);
            dfs(nums, x + 1, n);
            a.pop_back();
            dfs(nums, x + 1, n);
        }

        vector<vector<int>> subsets(vector<int>& nums) {
            int n = nums.size();

            dfs(nums, 0, n);
            return ans;
        }
};

// @lc code=end
