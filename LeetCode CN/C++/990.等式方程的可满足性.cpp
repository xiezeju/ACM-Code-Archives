/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 *
 * https://leetcode.cn/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (53.58%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    55.5K
 * Total Submissions: 103.6K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * 给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i]
 * 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b
 * 是小写字母（不一定不同），表示单字母变量名。
 *
 * 只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回
 * false。 
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：["a==b","b!=a"]
 * 输出：false
 * 解释：如果我们指定，a = 1 且 b =
 * 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
 *
 *
 * 示例 2：
 *
 * 输入：["b==a","a==b"]
 * 输出：true
 * 解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
 *
 *
 * 示例 3：
 *
 * 输入：["a==b","b==c","a==c"]
 * 输出：true
 *
 *
 * 示例 4：
 *
 * 输入：["a==b","b!=c","c==a"]
 * 输出：false
 *
 *
 * 示例 5：
 *
 * 输入：["c==c","b==d","x!=z"]
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] 和 equations[i][3] 是小写字母
 * equations[i][1] 要么是 '='，要么是 '!'
 * equations[i][2] 是 '='
 *
 *
 */

// @lc code=start

class UnionSet {
    public:
        vector<int> p;

    public:
        UnionSet(int n) {
            p.resize(n);
            iota(p.begin(), p.end(), 0);
        }

        int find(int x) { return p[x] == x ? x : find(p[x]); }

        bool merge(int i, int j) {
            int x = find(i);
            int y = find(j);
            if (x == y) {
                return false;
            }
            p[y] = x;
            return true;
        }

        bool connect(int x, int y) { return find(x) == find(y); }
};

class Solution {
    public:
        bool equationsPossible(vector<string>& equations) {

            UnionSet a(26);
            for (string& eq : equations) {
                if (eq[1] == '=') {
                    a.merge(eq[0] - 'a', eq[3] - 'a');
                }
            }
            for (string& eq : equations) {
                if (eq[1] == '!') {
                    if (a.connect(eq[0] - 'a', eq[3] - 'a')) {
                        return false;
                    }
                }
            }

            return true;
        }
};

// @lc code=end
