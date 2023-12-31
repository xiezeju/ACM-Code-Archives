/*
 * @lc app=leetcode.cn id=2736 lang=cpp
 *
 * [2736] 最大和查询
 *
 * https://leetcode.cn/problems/maximum-sum-queries/description/
 *
 * algorithms
 * Hard (40.69%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 7.8K
 * Testcase Example:  '[4,3,1,2]\n[2,4,9,5]\n[[4,1],[1,3],[2,5]]'
 *
 * 给你两个长度为 n 、下标从 0 开始的整数数组 nums1 和 nums2 ，另给你一个下标从
 * 1 开始的二维数组 queries ，其中 queries[i] = [xi, yi] 。
 *
 * 对于第 i 个查询，在所有满足 nums1[j] >= xi 且 nums2[j] >= yi 的下标 j (0 <= j
 * < n) 中，找出 nums1[j] + nums2[j] 的 最大值 ，如果不存在满足条件的 j 则返回
 * -1 。
 *
 * 返回数组 answer ，其中 answer[i] 是第 i 个查询的答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [4,3,1,2], nums2 = [2,4,9,5], queries = [[4,1],[1,3],[2,5]]
 * 输出：[6,10,7]
 * 解释：
 * 对于第 1 个查询：xi = 4 且 yi = 1 ，可以选择下标 j = 0 ，此时 nums1[j] >=
 * 4 且 nums2[j] >= 1 。nums1[j] + nums2[j] 等于 6 ，可以证明 6
 * 是可以获得的最大值。 对于第 2 个查询：xi = 1 且 yi = 3 ，可以选择下标 j =
 * 2 ，此时 nums1[j] >= 1 且 nums2[j] >= 3 。nums1[j] + nums2[j] 等于 10
 * ，可以证明 10 是可以获得的最大值。 对于第 3 个查询：xi = 2 且 yi = 5
 * ，可以选择下标 j = 3 ，此时 nums1[j] >= 2 且 nums2[j] >= 5 。nums1[j] +
 * nums2[j] 等于 7 ，可以证明 7 是可以获得的最大值。 因此，我们返回 [6,10,7] 。
 *
 *
 * 示例 2：
 *
 * 输入：nums1 = [3,2,5], nums2 = [2,3,4], queries = [[4,4],[3,2],[1,1]]
 * 输出：[9,9,9]
 * 解释：对于这个示例，我们可以选择下标 j = 2 ，该下标可以满足每个查询的限制。
 *
 *
 * 示例 3：
 *
 * 输入：nums1 = [2,1], nums2 = [2,3], queries = [[3,3]]
 * 输出：[-1]
 * 解释：示例中的查询 xi = 3 且 yi = 3 。对于每个下标 j ，都只满足 nums1[j] < xi
 * 或者 nums2[j] < yi 。因此，不存在答案。
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == nums2.length 
 * n == nums1.length 
 * 1 <= n <= 10^5
 * 1 <= nums1[i], nums2[i] <= 10^9 
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * xi == queries[i][1]
 * yi == queries[i][2]
 * 1 <= xi, yi <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
    public:
        struct Node {
                int l, r;
                int sum;
        };

        struct PII {
                int x, y;
        };

        vector<Node> t;

        vector<PII> w, p;

        void push_up(int p) {
            t[p].sum = max(t[p << 1].sum, t[p << 1 | 1].sum);
        }

        void build(int p, int l, int r) {
            if (l == r) {
                t[p] = {l, r, w[l - 1].x + w[l - 1].y};
            } else {
                t[p] = {l, r};
                int mid = l + r >> 1;
                build(p << 1, l, mid);
                build(p << 1 | 1, mid + 1, r);
                push_up(p);
            }
        }

        int query(int p, int l, int r) {
            if (l <= t[p].l && t[p].r <= r) {
                return t[p].sum;
            }
            int mid = t[p].l + t[p].r >> 1;
            int res = -1;
            if (mid >= l)
                res = max(query(p << 1, l, r), res);
            if (mid < r)
                res = max(query(p << 1 | 1, l, r), res);

            return res;
        }

        vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2,
                                      vector<vector<int>>& queries) {
            int n = nums1.size(), m = queries.size();
            for (int i = 0; i < n; i++) {
                p.emplace_back(PII{nums1[i], nums2[i]});
            }

            sort(p.begin(), p.end(),
                 [&](const PII& a, const PII& b) { return a.x < b.x; });

            for (int i = 0; i < n; i++) {
                // 单调栈维护y的值，如果栈里面的元素比栈外面的元素小，说明先前入栈的(x,y)的和必然比现在的(x,y)和要小【x已经按照升序排列】，直接丢弃
                // 最终(x,y)按照x升序，y为降序的规律排列
                while (!w.empty() && w.back().y < p[i].y) {
                    w.pop_back();
                }
                w.emplace_back(p[i]);
            }
            n = w.size();
            t.resize(4 * n);
            build(1, 1, n);

            vector<int> ans(m, -1);

            for (int i = 0; i < m; i++) {
                int left, right;
                int l = 0, r = n - 1;
                // 找出数组中 x >= queries[i][0]的最小下标
                while (l < r) {
                    int mid = l + r >> 1;
                    if (queries[i][0] <= w[mid].x) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }

                left = l;

                l = 0, r = n - 1;
                // 找出数组中 y >= queries[i][1]的最大下标
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (queries[i][1] <= w[mid].y) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                right = l;

                if (w[left].x >= queries[i][0] && w[right].y >= queries[i][1])
                    // 因为建树的时候下标从1开始，所以查找的起点和终点都要+1
                    ans[i] = query(1, left + 1, right + 1);
            }
            return ans;
        }
};

// @lc code=end
