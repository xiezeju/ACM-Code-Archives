/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 *
 * https://leetcode.cn/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (52.18%)
 * Likes:    320
 * Dislikes: 0
 * Total Accepted:    71.4K
 * Total Submissions: 136.9K
 * Testcase Example:  '["time","me","bell"]'
 *
 * 单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices
 * 组成，且满足：
 *
 *
 * words.length == indices.length
 * 助记字符串 s 以 '#' 字符结尾
 * 对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#'
 * 字符结束（但不包括 '#'）的 子字符串 恰好与 words[i] 相等
 *
 *
 * 给你一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度
 * 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：words = ["time", "me", "bell"]
 * 输出：10
 * 解释：一组有效编码为 s = "time#bell#" 和 indices = [0, 2, 5] 。
 * words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#'
 * 结束的子字符串，如加粗部分所示 "time#bell#" words[1] = "me" ，s 开始于
 * indices[1] = 2 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
 * words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#'
 * 结束的子字符串，如加粗部分所示 "time#bell#"
 *
 *
 * 示例 2：
 *
 *
 * 输入：words = ["t"]
 * 输出：2
 * 解释：一组有效编码为 s = "t#" 和 indices = [0] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * words[i] 仅由小写字母组成
 *
 *
 */

// @lc code=start
class Solution {
        class Trie {
            public:
                vector<Trie*> child;
                bool          mark;

                Trie() : child(26), mark(false) {}
        };

    public:
        Trie *root, *p;

        int minimumLengthEncoding(vector<string>& words) {
            root = new Trie();
            unordered_map<Trie*, int> m;

            for (int k = 0; k < words.size(); k++) {
                string str = words[k];
                p = root;
                int n = str.size();
                for (int i = n - 1; i >= 0; i--) {
                    int c = str[i] - 'a';
                    if (!p->child[c]) {
                        p->child[c] = new Trie();
                    }
                    p->mark = true;
                    p = p->child[c];
                }
                m[p] = k;
            }

            int ans = 0;
            for (auto& [node, v] : m) {
                if (!node->mark) {
                    ans += words[v].size() + 1;
                }
            }

            return ans;
        }
};

// @lc code=end
