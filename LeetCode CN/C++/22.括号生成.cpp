/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.49%)
 * Likes:    3419
 * Dislikes: 0
 * Total Accepted:    757.3K
 * Total Submissions: 977.2K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且
 * 有效的 括号组合。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：["()"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 8
 *
 *
 */

// @lc code=start
// 回溯法
/*
class Solution {
    public:
        vector<string> ans;
        string         a = "";
        char           ch[2] = {'(', ')'};

        bool check() {
            stack<char> s;
            for (char& c : a) {
                if (c == '(') {
                    s.push('(');
                } else {
                    if (s.empty()) {
                        return false;
                    }
                    s.pop();
                }
            }
            return s.empty();
        }

        void dfs(int n, int k) {

            if (2 * n == k) {
                if (check())
                    ans.emplace_back(a);
                return;
            }

            for (int i = 0; i < 2; i++) {
                a.push_back(ch[i]);
                dfs(n, k + 1);
                a.pop_back();
            }
        }

        vector<string> generateParenthesis(int n) {
            dfs(n, 0);
            return ans;
        }
};
*/

class Solution {
    public:
        vector<string> a;

        void dfs(string s, int l, int r) {
            if (l < 0 || l > r) {
                return;
            }

            if (l == 0 && r == 0) {
                a.emplace_back(s);
            }

            dfs(s + '(', l - 1, r);
            dfs(s + ')', l, r - 1);
        }

        vector<string> generateParenthesis(int n) {
            dfs("", n, n);
            return a;
        }
};

// @lc code=end
