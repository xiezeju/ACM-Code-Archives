/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.66%)
 * Likes:    6895
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1
 * 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */

// @lc code=start
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            if (nums1.size() > nums2.size()) {
                return findMedianSortedArrays(nums2, nums1);
            }

            int m = nums1.size();
            int n = nums2.size();

            if (m + n == 1) {
                return nums1.empty() ? nums2[0] : nums1[0];
            }

            /*
            将 nums1 和 nums2 视为两个有序集合，分别记为 A 和 B，
            在A和B中分别寻求一个划分点 i 和 j 使得 nums1[0...i-1] ∪
            nums2[0...j-1] 为左集合; nums1[i...m] ∪ nums2[j...n]为右集合
            左集合和右集合各自都是有序的，为了使左集合∪右集合有序，又因为各个集合都是单调递增的
            显然有左集合的最大值 <= 右集合的最小值，即
            max(nums1[i-1],nums2[j-1]) <= min(nums1[i],nums2[j])
            我们已经知道 nums1和nums2都是递增的，所以
            nums2[i-1] 肯定 <= nums1[i]，对 nums2 同理，
            所以只需要保证nums1[i-1] <= nums2[j] && nums2[j-1] <= nums1[i];

            划分需要保证数量条件：
            1. m+n为偶数的时候左右集合的数量相等，此时有： m-i + n-j == i + j
            2. m+n为奇数的时候左集合比右集合的数量多1，此时有：
                m-i + n-j + 1 = i+ j
            综合以上两种情况可以推出 j = (m+n+1 >> 1) - i;

            通过二分来寻找满足划分条件的划分点，最后如果m+n为奇数那么左集合的最大值就是中位数，
            否则中位数为 (左集合最大值 + 右集合最小值) / 2

            边界情况处理：
            1. nums1[-1] = nums2[-1] = -∞
            2. nums1[m] = nums2[n] = +∞

            另外需要注意的是: 假定 集合A中元素数量总是 <= 集合B中元素数量
            */

            int l = 0, r = m;
            int max_front = 0;
            int min_back = 0;

            // 使用 l<=r 可以确保两个数组其中一个为空的时候能正确处理
            while (l <= r) {
                int i = l + r >> 1;
                int j = (m + n + 1 >> 1) - i;

                int numi_im1 = i == 0 ? INT_MIN : nums1[i - 1];
                int numi = i == m ? INT_MAX : nums1[i];
                int numj_jm1 = j == 0 ? INT_MIN : nums2[j - 1];
                int numj = j == n ? INT_MAX : nums2[j];

                if (numi_im1 <= numj) {
                    max_front = max(numi_im1, numj_jm1);
                    min_back = min(numi, numj);
                    l = i + 1;
                } else {
                    r = i - 1;
                }
            }
            return ((m + n) & 1) ? max_front : (max_front + min_back) / 2.0;
        }
};

// @lc code=end
