/*
 * @lc app=leetcode.cn id=505 lang=cpp
 *
 * [505] 迷宫 II
 *
 * https://leetcode.cn/problems/the-maze-ii/description/
 *
 * algorithms
 * Medium (51.61%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 20.3K
 * Testcase Example:
 * '[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]\n[0,4]\n[4,4]'
 *
 * 迷宫中有一个球，它有空地 (表示为 0) 和墙 (表示为
 * 1)。球可以向上、向下、向左或向右滚过空地，但直到撞上墙之前它都不会停止滚动。当球停止时，它才可以选择下一个滚动方向。
 *
 * 给定 m × n 的迷宫(maze)，球的起始位置 (start = [startrow, startcol])
 * 和目的地 (destination = [destinationrow,
 * destinationcol])，返回球在目的地 (destination)
 * 停止的最短距离。如果球不能在目的地 (destination) 停止，返回 -1。
 *
 * 距离是指球从起始位置 ( 不包括 ) 到终点 ( 包括 ) 所经过的空地数。
 *
 * 你可以假设迷宫的边界都是墙 ( 见例子 )。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]],
 * start = [0,4], destination = [4,4]
 * 输出: 12
 * 解析: 一条最短路径 : left -> down -> left -> down -> right -> down -> right。
 * ⁠            总距离为 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12。
 *
 *
 *
 * 示例 2:
 *
 *
 *
 *
 * 输入: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]],
 * start = [0,4], destination = [3,2]
 * 输出: -1
 * 解析: 球不可能在目的地停下来。注意，你可以经过目的地，但不能在那里停下来。
 *
 *
 * 示例 3:
 *
 *
 * 输入: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]],
 * start = [4,3], destination = [0,1]
 * 输出: -1
 *
 *
 *
 *
 * 注意:
 *
 *
 * m == maze.length
 * n == maze[i].length
 * 1 <= m, n <= 100
 * maze[i][j] 是 0 或 1.
 * start.length == 2
 * destination.length == 2
 * 0 <= startrow, destinationrow < m
 * 0 <= startcol, destinationcol < n
 * 球和目的地都存在于一个空地中，它们最初不会处于相同的位置。
 *
 * 迷宫至少包含两个空地。
 *
 *
 *
 */

// @lc code=start
class Solution {
        typedef tuple<int, int, int> Node;

    public:
        int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                             vector<int>& destination) {
            int m = maze.size();
            int n = maze[0].size();

            vector<vector<long long>> dis(m, vector<long long>(n, 0x3f3f3f3f));
            dis[start[0]][start[1]] = 0;

            priority_queue<Node, vector<Node>, greater<Node>> q;
            q.push({0, start[0], start[1]});

            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};

            while (!q.empty()) {
                auto [d, x, y] = q.top();
                q.pop();
                if (dis[x][y] < d) {
                    continue;
                }
                for (int i = 0; i < 4; i++) {
                    int nx = x;
                    int ny = y;
                    int step = 0;
                    while (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                           maze[nx][ny] == 0) {
                        nx += dx[i];
                        ny += dy[i];
                        step++;
                    }
                    nx -= dx[i];
                    ny -= dy[i];
                    step--;
                    if (dis[nx][ny] > dis[x][y] + step) {
                        dis[nx][ny] = dis[x][y] + step;
                        q.push({dis[nx][ny], nx, ny});
                    }
                }
            }
            int ans = dis[destination[0]][destination[1]];

            return ans == 0x3f3f3f3f ? -1 : ans;
        }
};

// @lc code=end
