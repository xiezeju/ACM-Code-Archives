/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 *
 * https://leetcode.cn/problems/non-decreasing-array/description/
 *
 * algorithms
 * Medium (27.76%)
 * Likes:    765
 * Dislikes: 0
 * Total Accepted:    103.1K
 * Total Submissions: 371.4K
 * Testcase Example:  '[4,2,3]'
 *
 * 给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。
 * 
 * 我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [4,2,3]
 * 输出: true
 * 解释: 你可以通过把第一个 4 变成 1 来使得它成为一个非递减数列。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [4,2,1]
 * 输出: false
 * 解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<2) return true;
        for(int i=1,cnt=0;i<nums.size();i++){
            if(nums[i-1]>nums[i]){ //发现递减关系需要进行纠正
                if(i>1&&nums[i-2]>nums[i]&&i+1<nums.size()&&nums[i-1]>nums[i+1]) return false; //四个连续的数中不可能纠正的情况  
                else if(++cnt==2) return false; //纠正达到2次就返回false
            }
        }
        return true;
    }
};
// @lc code=end

