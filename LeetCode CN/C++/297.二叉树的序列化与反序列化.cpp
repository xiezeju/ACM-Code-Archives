/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 *
 * https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (59.02%)
 * Likes:    1179
 * Dislikes: 0
 * Total Accepted:    227.4K
 * Total Submissions: 385.2K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 *
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 *
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 *
 * 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,null,null,4,5]
 * 输出：[1,2,3,null,null,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [1,2]
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中结点数在范围 [0, 10^4] 内
 * -1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    public:
        const string _null = "#";
        const string sp = ",";

        string code;

        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            code = "";
            if (root == nullptr) {
                return code;
            }

            queue<TreeNode*> q;
            q.emplace(root);

            while (!q.empty()) {
                int t = q.size();
                while (t--) {
                    auto u = q.front();
                    q.pop();
                    if (u == nullptr) {
                        code += _null + sp;
                        continue;
                    }
                    code += to_string(u->val) + sp;

                    q.emplace(u->left);
                    q.emplace(u->right);
                }
            }
            return code;
        }

        vector<string> stringSplit(const string& str, char sp) {
            size_t         previous = 0;
            size_t         current = str.find(sp);
            vector<string> elems;
            while (current != string::npos) {
                if (current > previous) {
                    elems.push_back(str.substr(previous, current - previous));
                }
                previous = current + 1;
                current = str.find(sp, previous);
            }
            if (previous != str.size()) {
                elems.push_back(str.substr(previous));
            }
            return elems;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            if (data.empty()) {
                return nullptr;
            }
            vector<string> s = stringSplit(data, ',');
            TreeNode*      root = new TreeNode(atoi(s[0].c_str()));

            queue<TreeNode*> q;
            q.emplace(root);

            for (int i = 1; i < s.size();) {
                TreeNode* u = q.front();
                q.pop();

                string left = s[i++];
                if (left != _null) {
                    u->left = new TreeNode(atoi(left.c_str()));
                    q.emplace(u->left);
                }

                string right = s[i++];
                if (right != _null) {
                    u->right = new TreeNode(atoi(right.c_str()));
                    q.emplace(u->right);
                }
            }
            return root;
        }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
