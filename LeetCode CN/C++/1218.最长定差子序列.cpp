/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 *
 * https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/description/
 *
 * algorithms
 * Medium (51.35%)
 * Likes:    264
 * Dislikes: 0
 * Total Accepted:    47K
 * Total Submissions: 91.6K
 * Testcase Example:  '[1,2,3,4]\n1'
 *
 * 给你一个整数数组 arr 和一个整数 difference，请你找出并返回
 * arr 中最长等差子序列的长度，该子序列中相邻元素之间的差等于 difference 。
 *
 * 子序列 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从
 * arr 派生出来的序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = [1,2,3,4], difference = 1
 * 输出：4
 * 解释：最长的等差子序列是 [1,2,3,4]。
 *
 * 示例 2：
 *
 *
 * 输入：arr = [1,3,5,7], difference = 1
 * 输出：1
 * 解释：最长的等差子序列是任意单个元素。
 *
 *
 * 示例 3：
 *
 *
 * 输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
 * 输出：4
 * 解释：最长的等差子序列是 [7,5,3,1]。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10^4
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int longestSubsequence(vector<int>& arr, int difference) {
            int n = arr.size();

            unordered_map<int, int> dp;

            int ans = 0;

            for (int i = 0; i < n; i++) {
                dp[arr[i]] = dp[arr[i] - difference] + 1;
                ans = max(ans, dp[arr[i]]);
            }
            return ans;
        }
};

// @lc code=end
