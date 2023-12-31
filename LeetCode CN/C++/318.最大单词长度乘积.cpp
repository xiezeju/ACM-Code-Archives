/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 *
 * https://leetcode.cn/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (72.47%)
 * Likes:    490
 * Dislikes: 0
 * Total Accepted:    88.6K
 * Total Submissions: 122.7K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * 给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j])
 * 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * 输出：16
 * 解释：这两个单词为 "abcw", "xtfn"。
 *
 * 示例 2：
 *
 *
 * 输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
 * 输出：4
 * 解释：这两个单词为 "ab", "cd"。
 *
 * 示例 3：
 *
 *
 * 输入：words = ["a","aa","aaa","aaaa"]
 * 输出：0
 * 解释：不存在这样的两个单词。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] 仅包含小写字母
 *
 *
 */

// @lc code=start
class Solution {
    public:
        int maxProduct(vector<string>& words) {
            int                        ans = 0;
            int                        n = words.size();
            unordered_map<string, int> s;

            for (string& str : words) {
                int bit = 0;
                for (char& c : str) {

                    bit |= 1 << (c - 'a');
                }
                s[str] = bit;
            }

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (!(s[words[i]] & s[words[j]])) {
                        int a = words[i].size();
                        int b = words[j].size();
                        ans = max(ans, a * b);
                    }
                }
            }

            return ans;
        }
};

// @lc code=end
