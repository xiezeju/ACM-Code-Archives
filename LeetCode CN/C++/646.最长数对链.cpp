/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 *
 * https://leetcode.cn/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (62.55%)
 * Likes:    410
 * Dislikes: 0
 * Total Accepted:    71K
 * Total Submissions: 113.4K
 * Testcase Example:  '[[1,2],[2,3],[3,4]]'
 *
 * 给你一个由 n 个数对组成的数对数组 pairs ，其中 pairs[i] = [lefti,
 * righti] 且 lefti < righti 。
 *
 * 现在，我们定义一种 跟随 关系，当且仅当 b < c 时，数对 p2 = [c,
 * d] 才可以跟在 p1 = [a, b] 后面。我们用这种形式来构造 数对链 。
 *
 * 找出并返回能够形成的 最长数对链的长度 。
 *
 * 你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：pairs = [[1,2], [2,3], [3,4]]
 * 输出：2
 * 解释：最长的数对链是 [1,2] -> [3,4] 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：pairs = [[1,2],[7,8],[4,5]]
 * 输出：3
 * 解释：最长的数对链是 [1,2] -> [4,5] -> [7,8] 。
 *
 *
 *
 * 提示：
 *
 *
 * n == pairs.length
 * 1 <= n <= 1000
 * -1000 <= lefti < righti <= 1000
 *
 *
 */

// @lc code=start
class Solution {
    public:
        static bool cmp(vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        }

        int findLongestChain(vector<vector<int>>& pairs) {
            int n = pairs.size();

            sort(pairs.begin(), pairs.end(), cmp);

            vector<int> dp(n + 1, 1);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (pairs[j][1] < pairs[i][0]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }

            return *max_element(dp.begin(), dp.end());
        }
};

// @lc code=end
