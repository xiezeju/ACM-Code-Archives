/*
 * @lc app=leetcode.cn id=499 lang=cpp
 *
 * [499] 迷宫 III
 *
 * https://leetcode.cn/problems/the-maze-iii/description/
 *
 * algorithms
 * Hard (43.64%)
 * Likes:    67
 * Dislikes: 0
 * Total Accepted:    5K
 * Total Submissions: 11.4K
 * Testcase Example:
 * '[[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]]\n[4,3]\n[0,1]'
 *
 *
 * 由空地和墙组成的迷宫中有一个球。球可以向上（u）下（d）左（l）右（r）四个方向滚动，但在遇到墙壁前不会停止滚动。当球停下时，可以选择下一个方向。迷宫中还有一个洞，当球运动经过洞时，就会掉进洞里。
 *
 * 给定球的起始位置，目的地和迷宫，找出让球以最短距离掉进洞里的路径。 距离的定义是球从起始位置（不包括）到目的地（包括）经过的空地个数。通过'u',
 * 'd', 'l'
 * 和 'r'输出球的移动方向。 由于可能有多条最短路径， 请输出字典序最小的路径。如果球无法进入洞，输出"impossible"。
 *
 * 迷宫由一个0和1的二维数组表示。
 * 1表示墙壁，0表示空地。你可以假定迷宫的边缘都是墙壁。起始位置和目的地的坐标通过行号和列号给出。
 *
 *
 *
 * 示例1:
 *
 * 输入 1: 迷宫由以下二维数组表示
 *
 * 0 0 0 0 0
 * 1 1 0 0 1
 * 0 0 0 0 0
 * 0 1 0 0 1
 * 0 1 0 0 0
 *
 * 输入 2: 球的初始位置 (rowBall, colBall) = (4, 3)
 * 输入 3: 洞的位置 (rowHole, colHole) = (0, 1)
 *
 * 输出: "lul"
 *
 * 解析: 有两条让球进洞的最短路径。
 * 第一条路径是 左 -> 上 -> 左, 记为 "lul".
 * 第二条路径是 上 -> 左, 记为 'ul'.
 * 两条路径都具有最短距离6, 但'l' < 'u'，故第一条路径字典序更小。因此输出"lul"。
 *
 *
 *
 * 示例 2:
 *
 * 输入 1: 迷宫由以下二维数组表示
 *
 * 0 0 0 0 0
 * 1 1 0 0 1
 * 0 0 0 0 0
 * 0 1 0 0 1
 * 0 1 0 0 0
 *
 * 输入 2: 球的初始位置 (rowBall, colBall) = (4, 3)
 * 输入 3: 洞的位置 (rowHole, colHole) = (3, 0)
 *
 * 输出: "impossible"
 *
 * 示例: 球无法到达洞。
 *
 *
 *
 *
 *
 * 注意:
 *
 *
 * 迷宫中只有一个球和一个目的地。
 * 球和洞都在空地上，且初始时它们不在同一位置。
 * 给定的迷宫不包括边界 (如图中的红色矩形), 但你可以假设迷宫的边缘都是墙壁。
 * 迷宫至少包括2块空地，行数和列数均不超过30。
 *
 *
 */

// @lc code=start
class Solution {
    public:
        class Node {
            public:
                int    x, y;
                int    c_dis;
                string path;

                Node(int x, int y, int c_dis, string path) :
                    x(x), y(y), c_dis(c_dis), path(path) {}

                bool operator<(const Node& a) const { return c_dis > a.c_dis; }
        };

    public:
        string findShortestWay(vector<vector<int>>& maze, vector<int>& ball,
                               vector<int>& hole) {
            int m = maze.size();
            int n = maze[0].size();

            vector<vector<int>>    dis(m, vector<int>(n, 0x3f3f3f3f));
            vector<vector<string>> paths(m, vector<string>(n));
            priority_queue<Node>   q;

            q.push(Node(ball[0], ball[1], 0, ""));
            dis[ball[0]][ball[1]] = 0;

            int  dx[4] = {1, 0, 0, -1};
            int  dy[4] = {0, -1, 1, 0};
            char direct[4] = {'d', 'l', 'r', 'u'};

            while (!q.empty()) {
                auto [x, y, cur_dis, p] = q.top();
                q.pop();

                if (x == hole[0] && y == hole[1]) {
                    return paths[x][y];
                }

                if (dis[x][y] < cur_dis ||
                    (dis[x][y] == cur_dis && paths[x][y] > p)) {
                    continue;
                }

                dis[x][y] = cur_dis;

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    int step = 0;
                    while (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                           maze[nx][ny] == 0) {
                        step++;
                        if (nx == hole[0] && ny == hole[1]) {
                            nx += dx[i];
                            ny += dy[i];
                            break;
                        }

                        nx += dx[i];
                        ny += dy[i];
                    }
                    nx -= dx[i];
                    ny -= dy[i];
                    if (dis[nx][ny] > dis[x][y] + step ||
                        (dis[nx][ny] == dis[x][y] + step &&
                         paths[nx][ny] > p + direct[i])) {

                        dis[nx][ny] = dis[x][y] + step;
                        paths[nx][ny] = p + direct[i];
                        q.push({nx, ny, dis[nx][ny], p + direct[i]});
                    }
                }
            }

            return "impossible";
        }
};

// @lc code=end
