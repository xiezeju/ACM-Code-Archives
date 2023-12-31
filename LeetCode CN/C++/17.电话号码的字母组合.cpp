/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (58.47%)
 * Likes:    2672
 * Dislikes: 0
 * Total Accepted:    770.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按
 * 任意顺序 返回。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：digits = ""
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 *
 *
 */

// @lc code=start
class Solution {
    public:
        vector<string> s;
        vector<string> ans;

        vector<vector<bool>> vis;

        string a = "";

        void dfs(string digits, int k) {
            if (a.size() == digits.size()) {
                ans.emplace_back(a);
                return;
            }
            int x = digits[k] - '0';
            for (int i = 0; i < s[x].size(); i++) {

                vis[x][i] = true;
                a.push_back(s[x][i]);
                dfs(digits, k + 1);
                vis[x][i] = false;
                a.pop_back();
            }
        }

        vector<string> letterCombinations(string digits) {
            if (!digits.size()) {
                return {};
            }

            s.resize(10);
            s[2] = "abc";
            s[3] = "def";
            s[4] = "ghi";
            s[5] = "jkl";
            s[6] = "mno";
            s[7] = "pqrs";
            s[8] = "tuv";
            s[9] = "wxyz";

            vis.resize(10, vector<bool>(4));

            dfs(digits, 0);

            return ans;
        }
};

// @lc code=end
