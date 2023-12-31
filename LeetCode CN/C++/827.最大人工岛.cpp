/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 *
 * https://leetcode.cn/problems/making-a-large-island/description/
 *
 * algorithms
 * Hard (47.12%)
 * Likes:    375
 * Dislikes: 0
 * Total Accepted:    43.4K
 * Total Submissions: 92.1K
 * Testcase Example:  '[[1,0],[0,1]]'
 *
 * 给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
 *
 * 返回执行此操作后，grid 中最大的岛屿面积是多少？
 *
 * 岛屿 由一组上、下、左、右四个方向相连的 1 形成。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: grid = [[1, 0], [0, 1]]
 * 输出: 3
 * 解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
 *
 *
 * 示例 2:
 *
 *
 * 输入: grid = [[1, 1], [1, 0]]
 * 输出: 4
 * 解释: 将一格0变成1，岛屿的面积扩大为 4。
 *
 * 示例 3:
 *
 *
 * 输入: grid = [[1, 1], [1, 1]]
 * 输出: 4
 * 解释: 没有0可以让我们变成1，面积依然为 4。
 *
 *
 *
 * 提示：
 *
 *
 * n == grid.length
 * n == grid[i].length
 * 1
 * grid[i][j] 为 0 或 1
 *
 *
 */

// @lc code=start
class UnionSet {
    public:
        vector<int> p;
        vector<int> size;

    public:
        UnionSet(int n) {
            p.resize(n);
            iota(p.begin(), p.end(), 0);
            size.resize(n, 1);
        }

        int find(int x) { return p[x] == x ? x : find(p[x]); }

        void merge(int i, int j) {
            int x = find(i);
            int y = find(j);
            if (x == y)
                return;
            p[y] = x;
            size[x] += size[y];
        }
};

class Solution {
    public:
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        void dfs(vector<vector<int>>& grid, int x, int y,
                 vector<vector<bool>>& vis, int n, UnionSet& a) {

            vis[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] &&
                    grid[nx][ny] == 1) {
                    a.merge(n * x + y + 1, n * nx + ny + 1);
                    dfs(grid, nx, ny, vis, n, a);
                }
            }
        }

        int largestIsland(vector<vector<int>>& grid) {

            int n = grid.size();
            int ans = 0;

            UnionSet a(n * n + 1);

            vector<vector<bool>> vis(n, vector<bool>(n));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int idx = i * n + j + 1;
                    if (grid[i][j] == 0) {
                        a.size[idx] = 0;
                    }
                    if (grid[i][j] == 1 && !vis[i][j]) {

                        dfs(grid, i, j, vis, n, a);
                        ans = max(a.size[a.find(idx)], ans);
                    }
                }
            }
            unordered_set<int> valid;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0) {
                        int sum = 0;
                        for (int k = 0; k < 4; k++) {
                            int x = i + dx[k];
                            int y = j + dy[k];
                            int idx = n * x + y + 1;
                            if (x < 0 || x >= n || y < 0 || y >= n) {
                                continue;
                            }
                            int f = a.find(idx);
                            if (!valid.count(f)) {
                                sum += a.size[f];
                                valid.insert(f);
                            }
                        }
                        valid = unordered_set<int>();
                        ans = max(ans, sum + 1);
                    }
                }
            }

            return ans;
        }
};

// @lc code=end
