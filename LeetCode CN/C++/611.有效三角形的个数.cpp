/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 *
 * https://leetcode.cn/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (53.67%)
 * Likes:    534
 * Dislikes: 0
 * Total Accepted:    95.7K
 * Total Submissions: 178.7K
 * Testcase Example:  '[2,2,3,4]'
 *
 * 给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,2,3,4]
 * 输出: 3
 * 解释:有效的组合是:
 * 2,3,4 (使用第一个 2)
 * 2,3,4 (使用第二个 2)
 * 2,2,3
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [4,2,3,4]
 * 输出: 4
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int triangleNumber(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(), nums.end());

            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int sum = nums[i] + nums[j];
                    int l = j + 1, r = n - 1;
                    int k = j;
                    while (l <= r) {
                        int mid = l + r >> 1;
                        if (sum > nums[mid]) {
                            l = mid + 1;
                            k = mid;
                        } else {
                            r = mid - 1;
                        }
                    }

                    ans += k - j;
                }
            }
            return ans;
        }
};

// @lc code=end
