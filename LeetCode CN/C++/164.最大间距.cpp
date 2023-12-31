/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 *
 * https://leetcode.cn/problems/maximum-gap/description/
 *
 * algorithms
 * Medium (60.08%)
 * Likes:    600
 * Dislikes: 0
 * Total Accepted:    89.2K
 * Total Submissions: 148.5K
 * Testcase Example:  '[3,6,9,1]'
 *
 * 给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值
 * 。如果数组元素个数小于 2，则返回 0 。
 *
 * 您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [3,6,9,1]
 * 输出: 3
 * 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9)
 * 之间都存在最大差值 3。
 *
 * 示例 2:
 *
 *
 * 输入: nums = [10]
 * 输出: 0
 * 解释: 数组元素个数小于 2，因此返回 0。
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
// 基数排序做法
/*
class Solution {
    public:
        void radix_sort(vector<int>& a) {
            int n = a.size();
            int _max = *max_element(a.begin(), a.end());
            int max_len = 0;

            while (_max) {
                max_len++;
                _max /= 10;
            }

            int dev = 1;

            vector<int> cnt(10), t(n);

            for (int k = 0; k < max_len; k++) {
                for (auto& val : a) {
                    int x = val / dev % 10;
                    cnt[x]++;
                }

                for (int i = 1; i < cnt.size(); i++) {
                    cnt[i] += cnt[i - 1];
                }

                for (int i = n - 1; i >= 0; i--) {
                    int x = a[i] / dev % 10;
                    t[--cnt[x]] = a[i];
                }

                a = t;
                cnt = vector<int>(10);
                dev *= 10;
            }
        }

        int maximumGap(vector<int>& nums) {
            int n = nums.size();
            if (n < 2)
                return 0;
            radix_sort(nums);
            int ans = INT_MIN;
            for (int i = 1; i < n; i++) {
                ans = max(ans, abs(nums[i] - nums[i - 1]));
            }
            return ans;
        }
};
*/
// 桶排序做法
class Solution {
    public:
        void insert_sort(vector<int>& a) {
            int n = a.size();
            for (int i = 1; i < n; i++) {
                int cur = a[i];
                int j = i - 1;
                while (j >= 0 && cur < a[j]) {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = cur;
            }
        }

        void buket_sort(vector<int>& a) {
            int n = a.size();
            // 找出最大值和最小值以确定映射范围（通常这样做是为了处理有负数的情况）
            int _max = *max_element(a.begin(), a.end());
            int _min = *min_element(a.begin(), a.end());
            // 每个桶的大小至少为1
            int one_buket_size = (_max - _min) / n + 1;
            // 桶的数量至少为1
            int buket_num = (_max - _min) / one_buket_size + 1;

            vector<vector<int>> buket(buket_num);

            for (int i = 0; i < n; i++) {
                int index = (a[i] - _min) / one_buket_size;
                buket[index].emplace_back(a[i]);
            }

            int idx = 0;
            for (int i = 0; i < buket_num; i++) {
                // 对每个桶进行插入排序（小样本数使用插入排序性能优异）
                insert_sort(buket[i]);
                // 每个桶排序完之后放回原数组
                for (int j = 0; j < buket[i].size(); j++) {
                    a[idx++] = buket[i][j];
                }
            }
        }

        int maximumGap(vector<int>& nums) {
            int n = nums.size();
            if (n < 2)
                return 0;

            buket_sort(nums);

            int ans = 0;

            for (int i = 1; i < n; i++) {
                ans = max(ans, nums[i] - nums[i - 1]);
            }

            return ans;
        }
};

// @lc code=end
