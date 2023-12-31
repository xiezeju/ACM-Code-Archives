/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.08%)
 * Likes:    1525
 * Dislikes: 0
 * Total Accepted:    612K
 * Total Submissions: 794.2K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2：
 *
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */

// @lc code=start
class Solution {
    public:
        vector<vector<int>> ans;
        vector<int>         a;
        vector<bool>        vis;

        void dfs(int n, int k, int x) {

            if (a.size() == k) {
                ans.emplace_back(a);
                return;
            }

            for (int i = x; i <= n; i++) {
                if (vis[i])
                    continue;
                vis[x] = true;
                a.emplace_back(i);
                dfs(n, k, i + 1);
                a.pop_back();
                vis[x] = false;
            }
        }

        vector<vector<int>> combine(int n, int k) {
            vis.resize(n + 1);
            dfs(n, k, 1);
            return ans;
        }
};

// @lc code=end
