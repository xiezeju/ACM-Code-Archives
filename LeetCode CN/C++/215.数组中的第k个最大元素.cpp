/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (62.88%)
 * Likes:    2345
 * Dislikes: 0
 * Total Accepted:    950.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 *
 *
 * 示例 2:
 *
 *
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
// 快速排序做法
/*
class Solution {
    public:
        int target;
        int ans;

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

        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
            target = n - k;
            int l = 0, r = n - 1;
            while (true) {
                int mid = partion(nums, l, r);
                if (mid == target) {
                    return nums[target];
                } else if (mid < target) {
                    l = mid + 1;
                    // 关键优化，跳过相同的值，不然会超时
                    while (l < target && nums[l] == nums[l - 1])
                        l++;
                } else {
                    r = mid - 1;
                    while (r > target && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
};
*/
// 堆排序做法
class Solution {
    public:
        void maxHeap(vector<int>& a, int i, int heapSize) {
            int l = i << 1 | 1;
            int r = l + 1;

            int maxIndex = i;
            if (l < heapSize && a[l] > a[maxIndex]) {
                maxIndex = l;
            }
            if (r < heapSize && a[r] > a[maxIndex]) {
                maxIndex = r;
            }
            if (maxIndex != i) {
                swap(a[i], a[maxIndex]);
                maxHeap(a, maxIndex, heapSize);
            }
        }

        void buildHeap(vector<int>& a) {
            int n = a.size();
            for (int i = (n >> 1) - 1; i >= 0; i--) {
                maxHeap(a, i, n);
            }
        }

        void heapSort(vector<int>& a, int k) {
            int n = a.size();
            buildHeap(a);
            for (int i = n - 1; i >= n - (k - 1); i--) {
                swap(a[0], a[i]);
                maxHeap(a, 0, i);
            }
        }

        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
            heapSort(nums, k);
            return nums[0];
        }
};

// @lc code=end
