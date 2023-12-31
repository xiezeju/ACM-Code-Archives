/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
 *
 * https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
 *
 * algorithms
 * Medium (53.78%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    13.7K
 * Total Submissions: 24.6K
 * Testcase Example:  '[18,43,36,13,7]'
 *
 * 给你一个下标从 0 开始的数组 nums ，数组中的元素都是 正 整数。请你选出两个下标
 * i 和 j（i != j），且 nums[i] 的数位和 与 nums[j] 的数位和相等。
 *
 * 请你找出所有满足条件的下标 i 和 j ，找出并返回 nums[i] + nums[j] 可以得到的
 * 最大值 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [18,43,36,13,7]
 * 输出：54
 * 解释：满足条件的数对 (i, j) 为：
 * - (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
 * - (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
 * 所以可以获得的最大和是 54 。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [10,12,19,14]
 * 输出：-1
 * 解释：不存在满足条件的数对，返回 -1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            int         n = nums.size();
            vector<int> a;

            unordered_map<int, priority_queue<int>> m;
            for (auto& i : nums) {
                int x = i;
                int t = 0;
                while (x) {
                    t += x % 10;
                    x /= 10;
                }
                m[t].emplace(i);
            }
            int ans = -1;
            for (auto& [_, v] : m) {
                int tmp = 0;
                int t = 2;
                if (v.size() > 1) {
                    while (t--) {
                        tmp += v.top();
                        v.pop();
                    }
                    ans = max(ans, tmp);
                }
            }
            return ans;
        }
};

// @lc code=end
