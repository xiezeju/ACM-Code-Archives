/*
 * @lc app=leetcode.cn id=2262 lang=cpp
 *
 * [2262] 字符串的总引力
 *
 * https://leetcode.cn/problems/total-appeal-of-a-string/description/
 *
 * algorithms
 * Hard (57.86%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    7.5K
 * Total Submissions: 12.7K
 * Testcase Example:  '"abbca"'
 *
 * 字符串的 引力 定义为：字符串中 不同 字符的数量。
 *
 *
 * 例如，"abbca" 的引力为 3 ，因为其中有 3 个不同字符 'a'、'b' 和 'c' 。
 *
 *
 * 给你一个字符串 s ，返回 其所有子字符串的总引力 。
 *
 * 子字符串 定义为：字符串中的一个连续字符序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "abbca"
 * 输出：28
 * 解释："abbca" 的子字符串有：
 * - 长度为 1 的子字符串："a"、"b"、"b"、"c"、"a" 的引力分别为
 * 1、1、1、1、1，总和为 5 。
 * - 长度为 2 的子字符串："ab"、"bb"、"bc"、"ca" 的引力分别为 2、1、2、2
 * ，总和为 7 。
 * - 长度为 3 的子字符串："abb"、"bbc"、"bca" 的引力分别为 2、2、3 ，总和为 7 。
 * - 长度为 4 的子字符串："abbc"、"bbca" 的引力分别为 3、3 ，总和为 6 。
 * - 长度为 5 的子字符串："abbca" 的引力为 3 ，总和为 3 。
 * 引力总和为 5 + 7 + 7 + 6 + 3 = 28 。
 *
 *
 * 示例 2：
 *
 * 输入：s = "code"
 * 输出：20
 * 解释："code" 的子字符串有：
 * - 长度为 1 的子字符串："c"、"o"、"d"、"e" 的引力分别为 1、1、1、1 ，总和为 4
 * 。
 * - 长度为 2 的子字符串："co"、"od"、"de" 的引力分别为 2、2、2 ，总和为 6 。
 * - 长度为 3 的子字符串："cod"、"ode" 的引力分别为 3、3 ，总和为 6 。
 * - 长度为 4 的子字符串："code" 的引力为 4 ，总和为 4 。
 * 引力总和为 4 + 6 + 6 + 4 = 20 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
    public:
        long long appealSum(string s) {
            int n = s.size();

            unordered_map<char, vector<int>> m;

            for (int i = 0; i < n; i++) {
                m[s[i]].emplace_back(i);
            }

            long long ans = 0;
            for (auto&& [_, a] : m) {
                a.insert(a.begin(), -1);

                // 考虑当前位置的字符c能产生1贡献的范围：
                // 起点的选择区间为 (字符c上一次出现的位置, 字符c当前出现的位置]
                // 终点的选择区间为 [字符c当前出现的位置, 字符串s末尾]
                // 按照上方起点和终点的选择区间，一共有
                // (a[i] - a[i - 1]) * (n - a[i]) 个子串包含当前字符c
                for (int i = 1; i < a.size(); i++) {
                    ans += (a[i] - a[i - 1]) * (1ll) * (n - a[i]) * (1ll);
                }
            }
            return ans;
        }
};

// @lc code=end
