/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 *
 * https://leetcode.cn/problems/number-of-equivalent-domino-pairs/description/
 *
 * algorithms
 * Easy (54.20%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    44.9K
 * Total Submissions: 82.8K
 * Testcase Example:  '[[1,2],[2,1],[3,4],[5,6]]'
 *
 * 给你一个由一些多米诺骨牌组成的列表 dominoes。
 *
 * 如果其中某一张多米诺骨牌可以通过旋转 0 度或 180
 * 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。
 *
 * 形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c,
 * d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。
 *
 * 在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i]
 * 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。
 *
 *
 *
 * 示例：
 *
 * 输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= dominoes.length <= 40000
 * 1 <= dominoes[i][j] <= 9
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int ans = 0;
            int n = dominoes.size();

            vector<int> cnt(100);
            for (auto& i : dominoes) {
                int val = i[0] > i[1] ? i[0] * 10 + i[1] : i[1] * 10 + i[0];
                ans += cnt[val];
                cnt[val]++;
            }
            return ans;
        }
};

// @lc code=end
