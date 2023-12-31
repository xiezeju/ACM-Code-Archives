/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 *
 * https://leetcode.cn/problems/find-the-town-judge/description/
 *
 * algorithms
 * Easy (51.77%)
 * Likes:    312
 * Dislikes: 0
 * Total Accepted:    91.5K
 * Total Submissions: 176.9K
 * Testcase Example:  '2\n[[1,2]]'
 *
 * 小镇里有 n 个人，按从 1 到 n
 * 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。
 *
 * 如果小镇法官真的存在，那么：
 *
 *
 * 小镇法官不会信任任何人。
 * 每个人（除了小镇法官）都信任这位小镇法官。
 * 只有一个人同时满足属性 1 和属性 2 。
 *
 *
 * 给你一个数组 trust ，其中 trust[i] = [ai, bi] 表示编号为 ai 的人信任编号为 bi
 * 的人。
 *
 * 如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 2, trust = [[1,2]]
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 3, trust = [[1,3],[2,3]]
 * 输出：3
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 3, trust = [[1,3],[2,3],[3,1]]
 * 输出：-1
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1000
 * 0 <= trust.length <= 10^4
 * trust[i].length == 2
 * trust 中的所有trust[i] = [ai, bi] 互不相同
 * ai != bi
 * 1 <= ai, bi <= n
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int findJudge(int n, vector<vector<int>>& trust) {
            if (n == 1) {
                return 1;
            }

            unordered_map<int, int> in, out;
            for (auto t : trust) {
                out[t[0]]++;
                in[t[1]]++;
            }
            vector<int> judge;
            for (auto [k, v] : in) {
                if (v == n - 1) {
                    judge.emplace_back(k);
                }
            }
            if (judge.size() != 1) {
                return -1;
            }
            if (!out[judge[0]]) {
                return judge[0];
            }
            return -1;
        }
};

// @lc code=end
