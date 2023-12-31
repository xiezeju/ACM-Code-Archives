/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 *
 * https://leetcode.cn/problems/k-diff-pairs-in-an-array/description/
 *
 * algorithms
 * Medium (45.77%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    64.3K
 * Total Submissions: 140.5K
 * Testcase Example:  '[3,1,4,1,5]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k，请你在数组中找出 不同的 k-diff 数对，并返回不同的 k-diff 数对 的数目。
 * 
 * k-diff 数对定义为一个整数对 (nums[i], nums[j]) ，并满足下述全部条件：
 * 
 * 
 * 0 <= i, j < nums.length
 * i != j
 * nums[i] - nums[j] == k
 * 
 * 
 * 注意，|val| 表示 val 的绝对值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3, 1, 4, 1, 5], k = 2
 * 输出：2
 * 解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
 * 尽管数组中有两个 1 ，但我们只应返回不同的数对的数量。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1, 2, 3, 4, 5], k = 1
 * 输出：4
 * 解释：数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5) 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1, 3, 1, 5, 4], k = 0
 * 输出：1
 * 解释：数组中只有一个 0-diff 数对，(1, 1) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^7 <= nums[i] <= 10^7
 * 0 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
//哈希表做法

class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        unordered_set<int> s; //储存当前位置右边所有数的集合
        unordered_set<int> t;
        for(auto i:a){
            //每次检查当前位置右边的所有数，把满足diff-k最大的数加入集合t中
            if(s.count(i+k)) t.emplace(i+k);
            if(s.count(i-k)) t.emplace(i);
            s.emplace(i);
        }
        return t.size();
    }
};

//排序+双指针做法 需要满足: 1.排序 2.x<y 3.a[x] + k == a[y]

class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int n = a.size();
        int ans = 0;
        int y = 0;
        for(int x = 0; x<n; x++){
            if(x==0||a[x]!=a[x-1]){
                while(y<n&&(y<=x||a[y]<a[x]+k)) y++;
                if(y<n && a[x]+k==a[y]) ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

