/*
 * @lc app=leetcode.cn id=1168 lang=cpp
 *
 * [1168] 水资源分配优化
 *
 * https://leetcode.cn/problems/optimize-water-distribution-in-a-village/description/
 *
 * algorithms
 * Hard (62.38%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    3.1K
 * Total Submissions: 4.9K
 * Testcase Example:  '3\n[1,2,2]\n[[1,2,1],[2,3,1]]'
 *
 * 村里面一共有 n 栋房子。我们希望通过建造水井和铺设管道来为所有房子供水。
 *
 * 对于每个房子 i，我们有两种可选的供水方案：一种是直接在房子内建造水井，成本为 wells[i
 * - 1] （注意 -1 ，因为 索引从0开始
 * ）；另一种是从另一口井铺设管道引水，数组 pipes 给出了在房子间铺设管道的成本，其中每个 pipes[j]
 * = [house1j, house2j,
 * costj] 代表用管道将 house1j 和 house2j连接在一起的成本。连接是双向的。
 *
 * 请返回 为所有房子都供水的最低总成本 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
 * 输出：3
 * 解释：
 * 上图展示了铺设管道连接房屋的成本。
 * 最好的策略是在第一个房子里建造水井（成本为
 * 1），然后将其他房子铺设管道连起来（成本为 2），所以总成本为 3。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 2, wells = [1,1], pipes = [[1,2,1]]
 * 输出：2
 * 解释：我们可以用以下三种方法中的一种来提供低成本的水:
 * 选项1:
 * 在1号房子里面建一口井，成本为1
 * 在房子2内建造井，成本为1
 * 总成本是2。
 * 选项2:
 * 在1号房子里面建一口井，成本为1
 * -花费1连接房子2和房子1。
 * 总成本是2。
 * 选项3:
 * 在房子2内建造井，成本为1
 * -花费1连接房子1和房子2。
 * 总成本是2。
 * 注意，我们可以用cost 1或cost 2连接房子1和房子2，但我们总是选择最便宜的选项。
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 10^4
 * wells.length == n
 * 0 <= wells[i] <= 10^5
 * 1 <= pipes.length <= 10^4
 * pipes[j].length == 3
 * 1 <= house1j, house2j <= n
 * 0 <= costj <= 10^5
 * house1j != house2j
 *
 *
 */

// @lc code=start
class Solution {
        class edge {
            public:
                int x, y, cost;

                bool operator<(const edge& a) const { return cost < a.cost; }
        };

    public:
        vector<int> p;

        int find(int x) { return p[x] == x ? x : find(p[x]); }

        int minCostToSupplyWater(int n, vector<int>& wells,
                                 vector<vector<int>>& pipes) {
            int m = pipes.size();
            p.resize(n + 1);
            iota(p.begin(), p.end(), 0);
            vector<edge> e;

            for (int i = 0; i < n; i++) {
                e.emplace_back(edge{0, i + 1, wells[i]});
            }

            for (int i = 0; i < m; i++) {
                auto a = pipes[i];
                e.emplace_back(edge{a[0], a[1], a[2]});
            }

            sort(e.begin(), e.end());

            int ans = 0;
            for (int i = 0; i < e.size(); i++) {
                int x = find(e[i].x);
                int y = find(e[i].y);
                if (x == y) {
                    continue;
                }
                p[y] = x;
                ans += e[i].cost;
            }

            return ans;
        }
};

// @lc code=end
