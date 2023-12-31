/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 *
 * https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (60.80%)
 * Likes:    576
 * Dislikes: 0
 * Total Accepted:    48.4K
 * Total Submissions: 79.8K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤
 * j < n 。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,10,5,25,2,8]
 * 输出：28
 * 解释：最大运算结果是 5 XOR 25 = 28.
 *
 * 示例 2：
 *
 *
 * 输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
 * 输出：127
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2 * 10^5
 * 0 <= nums[i] <= 2^31 - 1
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
        class Trie {
            public:
                vector<Trie*> dic;

                Trie() : dic(2) {}
        };

    public:
        Trie* root = new Trie();

        int findMaximumXOR(vector<int>& nums) {
            Trie*     p;
            const int H = 30;
            int       ans = 0;
            for (int& a : nums) {
                p = root;
                for (int k = H; k >= 0; k--) {
                    int b = (a >> k) & 1;
                    if (!p->dic[b]) {
                        p->dic[b] = new Trie();
                    }
                    p = p->dic[b];
                }

                p = root;
                int x = 0;
                for (int k = H; k >= 0; k--) {
                    int b = (a >> k) & 1;
                    x <<= 1;
                    if (p->dic[!b]) {
                        x |= 1;
                        p = p->dic[!b];
                    } else {
                        p = p->dic[b];
                    }
                }
                ans = max(ans, x);
            }
            return ans;
        }
};

// @lc code=end
