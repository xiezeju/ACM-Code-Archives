/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 *
 * https://leetcode.cn/problems/running-sum-of-1d-array/description/
 *
 * algorithms
 * Easy (76.39%)
 * Likes:    437
 * Dislikes: 0
 * Total Accepted:    328K
 * Total Submissions: 429.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。
 * 
 * 请返回 nums 的动态和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：[1,3,6,10]
 * 解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,1,1,1,1]
 * 输出：[1,2,3,4,5]
 * 解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
 * 
 * 示例 3：
 * 
 * 输入：nums = [3,1,2,10,1]
 * 输出：[3,4,6,16,17]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * -10^6 <= nums[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& a) {
        int n = a.size();
        vector<int> c;
        c.resize(n+1);
        for(int i=0;i<n;i++)
            c[i+1] = c[i] + a[i];
        c.erase(c.begin());
        return c;
    }
};
// @lc code=end

