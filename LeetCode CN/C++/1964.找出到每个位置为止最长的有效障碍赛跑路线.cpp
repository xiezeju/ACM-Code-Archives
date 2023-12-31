/*
 * @lc app=leetcode.cn id=1964 lang=cpp
 *
 * [1964] 找出到每个位置为止最长的有效障碍赛跑路线
 *
 * https://leetcode.cn/problems/find-the-longest-valid-obstacle-course-at-each-position/description/
 *
 * algorithms
 * Hard (44.58%)
 * Likes:    48
 * Dislikes: 0
 * Total Accepted:    6.1K
 * Total Submissions: 13.7K
 * Testcase Example:  '[1,2,3,2]'
 *
 * 你打算构建一些障碍赛跑路线。给你一个 下标从 0 开始 的整数数组 obstacles
 * ，数组长度为 n ，其中 obstacles[i] 表示第 i 个障碍的高度。
 *
 * 对于每个介于 0 和 n - 1 之间（包含 0 和 n - 1）的下标  i
 * ，在满足下述条件的前提下，请你找出 obstacles 能构成的最长障碍路线的长度：
 *
 *
 * 你可以选择下标介于 0 到 i 之间（包含 0 和 i）的任意个障碍。
 * 在这条路线中，必须包含第 i 个障碍。
 * 你必须按障碍在 obstacles 中的 出现顺序 布置这些障碍。
 * 除第一个障碍外，路线中每个障碍的高度都必须和前一个障碍 相同 或者 更高 。
 *
 *
 * 返回长度为 n 的答案数组 ans ，其中 ans[i] 是上面所述的下标 i
 * 对应的最长障碍赛跑路线的长度。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：obstacles = [1,2,3,2]
 * 输出：[1,2,3,3]
 * 解释：每个位置的最长有效障碍路线是：
 * - i = 0: [1], [1] 长度为 1
 * - i = 1: [1,2], [1,2] 长度为 2
 * - i = 2: [1,2,3], [1,2,3] 长度为 3
 * - i = 3: [1,2,3,2], [1,2,2] 长度为 3
 *
 *
 * 示例 2：
 *
 *
 * 输入：obstacles = [2,2,1]
 * 输出：[1,2,1]
 * 解释：每个位置的最长有效障碍路线是：
 * - i = 0: [2], [2] 长度为 1
 * - i = 1: [2,2], [2,2] 长度为 2
 * - i = 2: [2,2,1], [1] 长度为 1
 *
 *
 * 示例 3：
 *
 *
 * 输入：obstacles = [3,1,5,6,4,2]
 * 输出：[1,1,2,3,2,2]
 * 解释：每个位置的最长有效障碍路线是：
 * - i = 0: [3], [3] 长度为 1
 * - i = 1: [3,1], [1] 长度为 1
 * - i = 2: [3,1,5], [3,5] 长度为 2, [1,5] 也是有效的障碍赛跑路线
 * - i = 3: [3,1,5,6], [3,5,6] 长度为 3, [1,5,6] 也是有效的障碍赛跑路线
 * - i = 4: [3,1,5,6,4], [3,4] 长度为 2, [1,4] 也是有效的障碍赛跑路线
 * - i = 5: [3,1,5,6,4,2], [1,2] 长度为 2
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == obstacles.length
 * 1 <= n <= 10^5
 * 1 <= obstacles[i] <= 10^7
 *
 *
 */

// @lc code=start
class Solution {
    public:
        vector<int>
        longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
            int         n = obstacles.size();
            vector<int> a, ans;

            for (auto& x : obstacles) {
                if (a.empty() || a.back() <= x) {
                    a.emplace_back(x);
                    ans.emplace_back(a.size());
                } else {
                    int i = upper_bound(a.begin(), a.end(), x) - a.begin();
                    ans.emplace_back(i + 1);
                    a[i] = x;
                }
            }

            return ans;
        }
};

// @lc code=end
