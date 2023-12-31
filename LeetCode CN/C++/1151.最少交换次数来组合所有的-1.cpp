/*
 * @lc app=leetcode.cn id=1151 lang=cpp
 *
 * [1151] 最少交换次数来组合所有的 1
 *
 * https://leetcode.cn/problems/minimum-swaps-to-group-all-1s-together/description/
 *
 * algorithms
 * Medium (52.97%)
 * Likes:    99
 * Dislikes: 0
 * Total Accepted:    9.7K
 * Total Submissions: 18.3K
 * Testcase Example:  '[1,0,1,0,1]'
 *
 * 给出一个二进制数组 data，你需要通过交换位置，将数组中 任何位置 上的 1
 * 组合到一起，并返回所有可能中所需 最少的交换次数。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: data = [1,0,1,0,1]
 * 输出: 1
 * 解释:
 * 有三种可能的方法可以把所有的 1 组合在一起：
 * [1,1,1,0,0]，交换 1 次；
 * [0,1,1,1,0]，交换 2 次；
 * [0,0,1,1,1]，交换 1 次。
 * 所以最少的交换次数为 1。
 *
 *
 * 示例  2:
 *
 *
 * 输入：data = [0,0,0,1,0]
 * 输出：0
 * 解释：
 * 由于数组中只有一个 1，所以不需要交换。
 *
 * 示例 3:
 *
 *
 * 输入：data = [1,0,1,0,1,0,0,1,1,0,1]
 * 输出：3
 * 解释：
 * 交换 3 次，一种可行的只用 3 次交换的解决方案是 [0,0,0,0,0,1,1,1,1,1,1]。
 *
 *
 * 示例 4:
 *
 *
 * 输入: data =
 * [1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1]
 * 输出: 8
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= data.length <= 10^5
 * data[i] == 0 or 1.
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int minSwaps(vector<int>& data) {
            int n = data.size();
            int ones = 0;
            for (int& x : data) {
                ones += x;
            }

            // 维护一个长度为 ones 的滑窗
            // 找出滑窗内1出现的最多次数
            int ans = 0;
            int l = 0, r = 0;
            int window_one = 0;
            while (r < n) {
                window_one += data[r];
                if (r - l + 1 > ones) {
                    window_one -= data[l];
                    l++;
                }
                ans = max(ans, window_one);
                r++;
            }
            // 剩下的 0 的个数就是需要交换的最小次数
            ans = ones - ans;
            return ans;
        }
};

// @lc code=end
