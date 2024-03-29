/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode.cn/problems/word-ladder/description/
 *
 * algorithms
 * Hard (48.30%)
 * Likes:    1309
 * Dislikes: 0
 * Total Accepted:    195.3K
 * Total Submissions: 404.3K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列
 * 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：
 *
 *
 * 每一对相邻的单词只差一个字母。
 * 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意，
 * beginWord 不需要在 wordList 中。 sk == endWord
 *
 *
 * 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord
 * 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0
 * 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * 输出：5
 * 解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * 返回它的长度 5。
 *
 *
 * 示例 2：
 *
 *
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * 输出：0
 * 解释：endWord "cog" 不在字典中，所以无法进行转换。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord、endWord 和 wordList[i] 由小写英文字母组成
 * beginWord != endWord
 * wordList 中的所有字符串 互不相同
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int bfs(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> wordSet(wordList.begin(), wordList.end());

            if (wordSet.find(endWord) == wordSet.end()) {
                return 0;
            }

            unordered_map<string, int> m;
            m[beginWord] = 1;

            queue<string> q;
            q.push(beginWord);
            while (!q.empty()) {
                string s = q.front();
                q.pop();

                int step = m[s];
                for (int i = 0; i < s.size(); i++) {
                    string t = s;
                    for (int j = 0; j < 26; j++) {
                        t[i] = j + 'a';
                        if (t == endWord)
                            return step + 1;
                        if (wordSet.find(t) != wordSet.end() &&
                            m.find(t) == m.end()) {
                            m[t] = step + 1;
                            q.push(t);
                        }
                    }
                }
            }
            return 0;
        }

        int ladderLength(string beginWord, string endWord,
                         vector<string>& wordList) {
            return bfs(beginWord, endWord, wordList);
        }
};

// @lc code=end
