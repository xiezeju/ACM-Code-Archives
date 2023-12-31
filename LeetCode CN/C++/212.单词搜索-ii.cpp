/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 *
 * https://leetcode.cn/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (43.61%)
 * Likes:    810
 * Dislikes: 0
 * Total Accepted:    96.9K
 * Total Submissions: 222.6K
 * Testcase Example:
 '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表
 words， 返回所有二维网格上的单词 。
 *
 * 单词必须按照字母顺序，通过 相邻的单元格
 * 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 * 输出：["eat","oath"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：board = [["a","b"],["c","d"]], words = ["abcb"]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 12
 * board[i][j] 是一个小写英文字母
 * 1 <= words.length <= 3 * 10^4
 * 1 <= words[i].length <= 10
 * words[i] 由小写英文字母组成
 * words 中的所有字符串互不相同
 *
 *
 */

// @lc code=start
class Solution {
        class Trie {
            public:
                vector<Trie*> child;
                bool          end;

                Trie() : child(26, nullptr), end(false) {}
        };

    public:
        Trie * root, *p;
        string s = "";

        vector<string>       ans;
        vector<vector<bool>> vis;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        Trie* check() {
            p = root;
            for (char& ch : s) {
                int c = ch - 'a';
                if (!p->child[c]) {
                    return nullptr;
                }
                p = p->child[c];
            }
            return p;
        }

        void dfs(vector<vector<char>>& board, int m, int n, int x, int y) {
            if (s.size() > 10) {
                return;
            }

            p = check();
            if (p == nullptr) {
                return;
            }
            if (p->end == true) {
                ans.emplace_back(s);
                p->end = false;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                    s.push_back(board[nx][ny]);
                    vis[nx][ny] = true;
                    dfs(board, m, n, nx, ny);
                    s.pop_back();
                    vis[nx][ny] = false;
                }
            }
        }

        vector<string> findWords(vector<vector<char>>& board,
                                 vector<string>&       words) {
            int m = board.size();
            int n = board[0].size();

            vis.resize(m, vector<bool>(n));

            root = new Trie();

            for (string& str : words) {
                p = root;
                for (char& ch : str) {
                    int c = ch - 'a';
                    if (!p->child[c]) {
                        p->child[c] = new Trie();
                    }
                    p = p->child[c];
                }
                p->end = true;
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    s.push_back(board[i][j]);
                    vis[i][j] = true;
                    dfs(board, m, n, i, j);
                    s.pop_back();
                    vis[i][j] = false;
                }
            }

            return ans;
        }
};

// @lc code=end
