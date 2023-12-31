/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 *
 * https://leetcode.cn/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (39.57%)
 * Likes:    517
 * Dislikes: 0
 * Total Accepted:    84.1K
 * Total Submissions: 212.3K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * 给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y
 * 平面上的一个点。求最多有多少个点在同一条直线上。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：points = [[1,1],[2,2],[3,3]]
 * 输出：3
 *
 *
 * 示例 2：
 *
 *
 * 输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * points[i].length == 2
 * -10^4 i, yi
 * points 中的所有点 互不相同
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int maxPoints(vector<vector<int>>& points) {
            int n = points.size();
            if (n <= 2)
                return n;
            int ans = 1;
            for (int i = 0; i < n; i++) {
                if (ans >= n - i || ans > n / 2) {
                    break;
                }
                unordered_map<int, int> s;
                for (int j = i + 1; j < n; j++) {
                    int dx = points[i][0] - points[j][0];
                    int dy = points[i][1] - points[j][1];

                    if (!dx) {
                        dy = 1;
                    } else if (!dy) {
                        dx = 1;
                    } else {
                        if (dy < 0) {
                            dx = -dx;
                            dy = -dy;
                        }

                        int gcd = __gcd(abs(dx), abs(dy));
                        dx /= gcd, dy /= gcd;
                    }
                    s[dy + 20001 * dx]++;
                }
                for (auto& [_, v] : s) {
                    ans = max(ans, v + 1);
                }
            }
            return ans;
        }
};

// @lc code=end
