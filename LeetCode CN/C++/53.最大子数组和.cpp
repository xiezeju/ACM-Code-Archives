/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (54.92%)
 * Likes:    6366
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 2.8M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 子数组 是数组中的一个连续部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * 
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 * 
 */

// @lc code=start
//分治解法

class Solution {
public:
    struct Node{
        int lsum,rsum,isum,msum;
    };

    Node sum(Node l,Node r){
        int isum = l.isum+r.isum;
        int lsum = max(l.lsum,l.isum+r.lsum);
        int rsum = max(r.rsum,l.rsum+r.isum);
        int msum = max(l.rsum+r.lsum,max(l.msum,r.msum));

        return Node{lsum,rsum,isum,msum};
    }

    Node getSum(vector<int>& a,int l,int r){
        if(l==r){
            return Node{a[l],a[l],a[l],a[l]};
        };
        int mid = (l + r)/2;
        Node left = getSum(a,l,mid);
        Node right = getSum(a,mid+1,r);
        return sum(left,right);

    }

    int maxSubArray(vector<int>& nums) {
        return getSum(nums,0,nums.size()-1).msum;
    }
};

//动态规划解法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN,pre=0;
        for(auto& i:nums){
            pre = max(i,pre+i);
            ans = max(ans,pre);
        }
        return ans;
    }
};
// @lc code=end

