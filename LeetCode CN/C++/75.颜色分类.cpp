/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode.cn/problems/sort-colors/description/
 *
 * algorithms
 * Medium (60.64%)
 * Likes:    1690
 * Dislikes: 0
 * Total Accepted:    579.3K
 * Total Submissions: 953.9K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色、共 n
 * 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 *
 * 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 *
 *
 *
 *
 * 必须在不使用库内置的 sort 函数的情况下解决这个问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] 为 0、1 或 2
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 *
 *
 */

// @lc code=start
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int i = -1;
            int j = n;
            int cur = 0;
            while (cur < n) {
                if (nums[cur] == 0) {
                    i++;
                    nums[i] = 0;
                }
                if (nums[cur] == 2) {
                    j--;
                }
                cur++;
            }
            i++;
            while (i < j) {
                nums[i] = 1;
                i++;
            }
            while (j < n) {
                nums[j] = 2;
                j++;
            }
        }
};

// @lc code=end
