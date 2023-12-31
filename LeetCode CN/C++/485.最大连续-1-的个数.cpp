/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 *
 * https://leetcode.cn/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (61.07%)
 * Likes:    411
 * Dislikes: 0
 * Total Accepted:    215.6K
 * Total Submissions: 353.1K
 * Testcase Example:  '[1,1,0,1,1,1]'
 *
 * 给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,0,1,1,1]
 * 输出：3
 * 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums = [1,0,1,1,0,1]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] 不是 0 就是 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        int cnt = 0;
        for(int i=0,j=0;i<n;i++){
            if(a[i]==1){
                cnt++;
                ans = max(ans,cnt);
            }else cnt = 0;
        }
        return ans;
    }
};
// @lc code=end

