/*
 * @lc app=leetcode.cn id=2127 lang=cpp
 *
 * [2127] 参加会议的最多员工数
 *
 * https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/description/
 *
 * algorithms
 * Hard (35.68%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 26.5K
 * Testcase Example:  '[2,2,1,2]'
 *
 * 一个公司准备组织一场会议，邀请名单上有 n 位员工。公司准备了一张
 * 圆形 的桌子，可以坐下 任意数目 的员工。
 *
 * 员工编号为 0 到 n - 1 。每位员工都有一位
 * 喜欢 的员工，每位员工 当且仅当 他被安排在喜欢员工的旁边，他才会参加会议。每位员工喜欢的员工
 * 不会 是他自己。
 *
 * 给你一个下标从
 * 0 开始的整数数组 favorite ，其中 favorite[i] 表示第 i 位员工喜欢的员工。请你返回参加会议的 最多员工数目
 * 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：favorite = [2,2,1,2]
 * 输出：3
 * 解释：
 * 上图展示了公司邀请员工 0，1 和 2 参加会议以及他们在圆桌上的座位。
 * 没办法邀请所有员工参与会议，因为员工 2 没办法同时坐在 0，1 和 3 员工的旁边。
 * 注意，公司也可以邀请员工 1，2 和 3 参加会议。
 * 所以最多参加会议的员工数目为 3 。
 *
 *
 * 示例 2：
 *
 * 输入：favorite = [1,2,0]
 * 输出：3
 * 解释：
 * 每个员工都至少是另一个员工喜欢的员工。所以公司邀请他们所有人参加会议的前提是所有人都参加了会议。
 * 座位安排同图 1 所示：
 * - 员工 0 坐在员工 2 和 1 之间。
 * - 员工 1 坐在员工 0 和 2 之间。
 * - 员工 2 坐在员工 1 和 0 之间。
 * 参与会议的最多员工数目为 3 。
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：favorite = [3,0,1,4,1]
 * 输出：4
 * 解释：
 * 上图展示了公司可以邀请员工 0，1，3 和 4 参加会议以及他们在圆桌上的座位。
 * 员工 2 无法参加，因为他喜欢的员工 0 旁边的座位已经被占领了。
 * 所以公司只能不邀请员工 2 。
 * 参加会议的最多员工数目为 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == favorite.length
 * 2 <= n <= 10^5
 * 0 <= favorite[i] <= n - 1
 * favorite[i] != i
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int maximumInvitations(vector<int>& favorite) {
            int         n = favorite.size();
            vector<int> indeg(n);
            vector<int> dp(n, 1);

            for (int i = 0; i < n; i++) {
                indeg[favorite[i]]++;
            }

            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (!indeg[i]) {
                    q.push(i);
                }
            }

            vector<bool> vis(n);

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                vis[u] = true;
                indeg[favorite[u]]--;
                dp[favorite[u]] = max(dp[u] + 1, dp[favorite[u]]);
                if (!indeg[favorite[u]]) {
                    q.push(favorite[u]);
                }
            }

            int rings_max = 0, twowaystep = 0;
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    // 说明环的长度为2，需要找出双向游走的最长边
                    if (favorite[favorite[i]] == i) {
                        twowaystep += dp[favorite[i]] + dp[i];
                        vis[favorite[i]] = true;
                        vis[i] = true;
                    } else {
                        // 当环的长度大于3时，需要找出最大环的长度
                        int count = 0, cur = i;
                        while (true) {
                            count++;
                            cur = favorite[cur];
                            vis[cur] = true;
                            if (cur == i) {
                                break;
                            }
                        }
                        rings_max = max(rings_max, count);
                    }
                }
            }
            return max(rings_max, twowaystep);
        }
};

// @lc code=end
