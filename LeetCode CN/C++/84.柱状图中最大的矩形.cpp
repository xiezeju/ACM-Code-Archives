/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (45.18%)
 * Likes:    2582
 * Dislikes: 0
 * Total Accepted:    368.7K
 * Total Submissions: 815.8K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为
 * 1 。
 *
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入： heights = [2,4]
 * 输出： 4
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 *
 *
 */

// @lc code=start
// 单调栈常数优化做法
/*
class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int         maxs = 0;
            int         n = heights.size();
            stack<int>  s;
            vector<int> l(n), r(n);

            for (int i = 0; i < n; i++) {
                r[i] = n;
                while (!s.empty() && heights[s.top()] >= heights[i]) {
                    r[s.top()] = i;
                    s.pop();
                }
                l[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }

            for (int i = 0; i < n; i++) {
                maxs = max(maxs, (r[i] - l[i] - 1) * heights[i]);
            }

            return maxs;
        }
};
*/
// 单调栈常规做法

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {

            int         n = heights.size();
            stack<int>  s;
            vector<int> l(n), r(n);

            for (int i = 0; i < n; i++) {
                while (!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                l[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }

            s = stack<int>();

            for (int i = n - 1; i >= 0; i--) {
                while (!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }

                r[i] = s.empty() ? n : s.top();
                s.push(i);
            }

            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans = max(ans, (r[i] - l[i] - 1) * heights[i]);
            }

            return ans;
        }
};

// @lc code=end
