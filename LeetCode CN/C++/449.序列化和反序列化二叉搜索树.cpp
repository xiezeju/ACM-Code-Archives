/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 *
 * https://leetcode.cn/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (62.26%)
 * Likes:    530
 * Dislikes: 0
 * Total Accepted:    65.4K
 * Total Submissions: 105K
 * Testcase Example:  '[2,1,3]'
 *
 * 序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
 *
 * 设计一个算法来序列化和反序列化 二叉搜索树 。
 * 对序列化/反序列化算法的工作方式没有限制。
 * 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
 *
 * 编码的字符串应尽可能紧凑。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [2,1,3]
 * 输出：[2,1,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数范围是 [0, 10^4]
 * 0 <= Node.val <= 10^4
 * 题目数据 保证 输入的树是一棵二叉搜索树。
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
                    TreeNode* u = q.front();
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

        vector<string> splitString(const string& str, char sp) {

            size_t         previous = 0;
            size_t         current = str.find(sp);
            vector<string> res;

            while (current != string::npos) {
                if (current > previous) {
                    res.emplace_back(str.substr(previous, current - previous));
                }
                previous = current + 1;
                current = str.find(sp, previous);
            }
            if (previous != str.size()) {
                res.emplace_back(str.substr(previous));
            }

            return res;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            if (data.empty()) {
                return nullptr;
            }

            vector<string> s = splitString(data, ',');

            TreeNode* root = new TreeNode(atoi(s[0].c_str()));

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
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
