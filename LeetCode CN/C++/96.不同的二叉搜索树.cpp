/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode.cn/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (70.92%)
 * Likes:    2385
 * Dislikes: 0
 * Total Accepted:    400.6K
 * Total Submissions: 564.9K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树
 * 有多少种？返回满足题意的二叉搜索树的种数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：5
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int numTrees(int n) {
            vector<int> G(n + 1);
            G[0] = 1;
            G[1] = 1;
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    G[i] += G[j - 1] * G[i - j];
                }
            }
            return G[n];
        }
};

// @lc code=end
