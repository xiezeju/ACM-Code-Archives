/*
 * @lc app=leetcode.cn id=269 lang=cpp
 *
 * [269] 火星词典
 *
 * https://leetcode.cn/problems/alien-dictionary/description/
 *
 * algorithms
 * Hard (36.88%)
 * Likes:    285
 * Dislikes: 0
 * Total Accepted:    13.2K
 * Total Submissions: 35.8K
 * Testcase Example:  '["wrt","wrf","er","ett","rftt"]'
 *
 * 现有一种使用英语字母的火星语言，这门语言的字母顺序对你来说是未知的。
 *
 * 给你一个来自这种外星语言字典的字符串列表 words ，words 中的字符串已经
 * 按这门新语言的字母顺序进行了排序 。
 *
 * 如果这种说法是错误的，并且给出的 words 不能对应任何字母的顺序，则返回 "" 。
 *
 * 否则，返回一个按新语言规则的 字典递增顺序
 * 排序的独特字符串。如果有多个解决方案，则返回其中 任意一个 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：words = ["wrt","wrf","er","ett","rftt"]
 * 输出："wertf"
 *
 *
 * 示例 2：
 *
 *
 * 输入：words = ["z","x"]
 * 输出："zx"
 *
 *
 * 示例 3：
 *
 *
 * 输入：words = ["z","x","z"]
 * 输出：""
 * 解释：不存在合法字母顺序，因此返回 "" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
    public:
        string alienOrder(vector<string>& words) {

            unordered_map<char, vector<char>> g;
            unordered_map<char, int>          indegree;

            int n = words.size();
            for (auto& word : words) {
                for (int i = 0; i < word.size(); i++) {
                    char c = word[i];
                    if (!g.count(c)) {
                        g[c] = vector<char>();
                    }
                }
            }

            // 建图
            for (int i = 1; i < n; i++) {
                int len1 = words[i - 1].size();
                int len2 = words[i].size();
                int length = min(len1, len2);
                int j = 0;
                while (j < length) {
                    char c1 = words[i - 1][j];
                    char c2 = words[i][j];
                    if (c1 != c2) {
                        g[c1].emplace_back(c2);
                        indegree[c2]++;
                        break;
                    }

                    j++;
                }
                if (j == length && len1 > len2) {
                    return "";
                }
            }

            queue<char> q;

            string ans = "";

            for (auto& [k, _] : g) {
                if (!indegree.count(k)) {
                    q.push(k);
                }
            }

            while (!q.empty()) {
                char u = q.front();
                q.pop();

                ans += u;

                for (char& x : g[u]) {
                    indegree[x]--;
                    if (!indegree[x]) {
                        q.push(x);
                    }
                }
            }

            if (ans.size() != g.size()) {
                return "";
            }

            return ans;
        }
};

// @lc code=end
