/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode.cn/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (50.57%)
 * Likes:    937
 * Dislikes: 0
 * Total Accepted:    589K
 * Total Submissions: 1.2M
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 *
 *
 */

// @lc code=start

// 快速排序做法
/*
class Solution {
    public:
        int partion(vector<int>& nums, int l, int r) {
            int re = l + rand() % (r - l + 1);
            swap(nums[re], nums[l]);
            int i = l, j = r;
            while (i < j) {
                while (i < j && nums[j] >= nums[l])
                    j--;
                while (i < j && nums[i] <= nums[l])
                    i++;
                swap(nums[i], nums[j]);
            }
            swap(nums[i], nums[l]);
            return i;
        }

        void quick_sort(vector<int>& nums, int l, int r) {
            if (l >= r)
                return;
            int mid = partion(nums, l, r);

            // 关键优化，跳过所有与基准数相同数
            int i = mid - 1;
            int j = mid + 1;
            while (i > l && nums[i] == nums[i + 1])
                i--;
            while (j < r && nums[j] == nums[j - 1])
                j++;
            quick_sort(nums, l, i);
            quick_sort(nums, j, r);
        }

        vector<int> sortArray(vector<int>& nums) {
            int n = nums.size();
            quick_sort(nums, 0, n - 1);
            return nums;
        }
};


// 希尔排序做法

class Solution {
    public:
        void shell_sort_Hibbrad(vector<int>& a) {
            int         n = a.size();
            int         h = 1;
            vector<int> gap;
            while ((1 << h) - 1 < n) {
                gap.emplace_back((1 << h++) - 1);
            }
            for (int k = gap.size() - 1; k >= 0; k--) {
                int h = gap[k];
                for (int i = h; i < n; i++) {
                    int j = i;
                    while (j >= h && a[j] < a[j - h]) {
                        swap(a[j], a[j - h]);
                        j -= h;
                    }
                }
            }
        }

        vector<int> sortArray(vector<int>& nums) {
            shell_sort_Hibbrad(nums);
            return nums;
        }
};
*/
// 计数排序做法
class Solution {
    public:
        vector<int> counting_sort(vector<int>& a) {
            int n = a.size();
            int _max = *max_element(a.begin(), a.end());
            int _min = *min_element(a.begin(), a.end());
            int len = _max - _min + 1;

            vector<int> cnt(len, 0);
            vector<int> tmp(n, 0);

            for (int i = 0; i < n; i++) {
                cnt[a[i] - _min]++;
            }
            cnt[0]--;
            for (int i = 1; i < len; i++) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                tmp[cnt[a[i] - _min]--] = a[i];
            }
            return tmp;
        }

        vector<int> sortArray(vector<int>& nums) { return counting_sort(nums); }
};

// @lc code=end
