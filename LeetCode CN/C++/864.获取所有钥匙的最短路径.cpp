/*
 * @lc app=leetcode.cn id=864 lang=cpp
 *
 * [864] 获取所有钥匙的最短路径
 *
 * https://leetcode.cn/problems/shortest-path-to-get-all-keys/description/
 *
 * algorithms
 * Hard (59.39%)
 * Likes:    271
 * Dislikes: 0
 * Total Accepted:    21.5K
 * Total Submissions: 36.2K
 * Testcase Example:  '["@.a..","###.#","b.A.B"]'
 *
 * 给定一个二维网格 grid ，其中：
 *
 *
 * '.' 代表一个空房间
 * '#' 代表一堵墙
 * '@' 是起点
 * 小写字母代表钥匙
 * 大写字母代表锁
 *
 *
 *
 * 我们从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间。我们不能在网格外面行走，也无法穿过一堵墙。如果途经一个钥匙，我们就把它捡起来。除非我们手里有对应的钥匙，否则无法通过锁。
 *
 * 假设 k 为 钥匙/锁 的个数，且满足 1 <= k <= 6，字母表中的前 k
 * 个字母在网格中都有自己对应的一个小写和一个大写字母。换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁。另外，代表钥匙和锁的字母互为大小写并按字母顺序排列。
 *
 * 返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：grid = ["@.a.#","###.#","b.A.B"]
 * 输出：8
 * 解释：目标是获得所有钥匙，而不是打开所有锁。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：grid = ["@..aA","..B#.","....b"]
 * 输出：6
 *
 *
 * 示例 3:
 *
 *
 * 输入: grid = ["@Aa"]
 * 输出: -1
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 30
 * grid[i][j] 只含有 '.', '#', '@', 'a'-'f' 以及 'A'-'F'
 * 钥匙的数目范围是 [1, 6] 
 * 每个钥匙都对应一个 不同 的字母
 * 每个钥匙正好打开一个对应的锁
 *
 *
 */

// @lc code=start
class Solution {
    public:
        unordered_map<char, int> Keys;

        int shortestPathAllKeys(vector<string>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};

            int sx, sy;
            int keynums = 0;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (islower(grid[i][j])) {
                        keynums++;
                    } else if (grid[i][j] == '@') {
                        sx = i, sy = j;
                        grid[i][j] = '.';
                    }
                }
            }

            struct State {
                    int x, y;
                    int key;
            };

            vector<vector<vector<bool>>> vis(
                m, vector<vector<bool>>(n, vector<bool>(1 << keynums)));

            int ans = 0;

            queue<State> q;
            q.push(State{sx, sy, 0});

            while (!q.empty()) {
                for (int t = q.size(); t; t--) {

                    State u = q.front();
                    q.pop();

                    if (u.key == (1 << keynums) - 1) {
                        return ans;
                    }

                    for (int i = 0; i < 4; i++) {
                        int nx = u.x + dx[i];
                        int ny = u.y + dy[i];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                            char c = grid[nx][ny];
                            int  k = u.key;
                            if (c == '#' ||
                                isupper(c) && ((k >> (c - 'A')) & 1) == 0) {
                                continue;
                            }
                            if (islower(c)) {
                                k |= 1 << (c - 'a');
                            }
                            if (!vis[nx][ny][k]) {
                                vis[nx][ny][k] = true;
                                q.push(State{nx, ny, k});
                            }
                        }
                    }
                }
                ans++;
            }

            return -1;
        }
};

// @lc code=end
