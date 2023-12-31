/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 *
 * https://leetcode.cn/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (30.72%)
 * Likes:    969
 * Dislikes: 0
 * Total Accepted:    80.8K
 * Total Submissions: 262.5K
 * Testcase Example:  '1\n2'
 *
 * 给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。
 *
 * 已知存在楼层 f ，满足 0  ，任何从 高于 f 的楼层落下的鸡蛋都会碎，从 f
 * 楼层或比它低的楼层落下的鸡蛋都不会破。
 *
 * 每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1
 * ）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中
 * 重复使用 这枚鸡蛋。
 *
 * 请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？
 *
 *
 * 示例 1：
 *
 *
 * 输入：k = 1, n = 2
 * 输出：2
 * 解释：
 * 鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。
 * 否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。
 * 如果它没碎，那么肯定能得出 f = 2 。
 * 因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。
 *
 *
 * 示例 2：
 *
 *
 * 输入：k = 2, n = 6
 * 输出：3
 *
 *
 * 示例 3：
 *
 *
 * 输入：k = 3, n = 14
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */

// @lc code=start
// 动态规划+二分
/*
class Solution {
    public:
        unordered_map<int, int> m;

        int dp(int k, int n) {
            int index = 100 * n + k;
            if (m.count(index) == 0) {
                int ans;
                if (n == 0 || k == 0)
                    return 0;
                else if (k == 1)
                    return n;
                else if (k >= n) {
                    return ceil(log2(n + 1));
                } else {
                    int l = 1, r = n;
                    int peek = INT_MAX;
                    while (l < r) {
                        int mid = l + r >> 1;
                        int broked = dp(k - 1, mid - 1);
                        int no_broked = dp(k, n - mid);
                        if (broked < no_broked) {
                            l = mid + 1;
                            peek = min(peek, no_broked);
                        } else {
                            r = mid;
                            peek = min(peek, broked);
                        }
                        ans = 1 + peek;
                    }
                    m[index] = ans;
                }
            }
            return m[index];
        }

        int superEggDrop(int k, int n) { return dp(k, n); }
};
*/

class Solution {
    public:
        int calF(int k, int t) {
            // 边界条件：
            // 1.
            // 当只有一个蛋的时候(k==1)只能从最低楼层向最高楼层走，一层一层扔，此时可以确定的楼层数为t+1层
            // 2.
            // 当只有一次操作机会的时候，无论有多少个蛋，都相当于只有一个蛋，此时可以能确定的楼层数也为t+1层
            if (k == 1 || t == 1) {
                return t + 1;
            }
            // 返回蛋碎了和没碎两种情况的和，无论有没有碎都要进行一次操作
            return calF(k - 1, t - 1) + calF(k, t - 1);
        }

        int superEggDrop(int k, int n) {
            // 操作次数从1向上递增
            int t = 1;
            // 当操作次数递增时能确定的楼层超过n了，说明这个时候的t就是确定楼层数所需的最小操作次数
            while (calF(k, t) <= n) {
                t++;
            }
            return t;
        }
};

// @lc code=end
