/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 *
 * https://leetcode.cn/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (52.20%)
 * Likes:    631
 * Dislikes: 0
 * Total Accepted:    71K
 * Total Submissions: 135.4K
 * Testcase Example:
 * '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * 给你一个数组 nums ，请你完成两类查询。
 *
 *
 * 其中一类查询要求 更新 数组 nums 下标对应的值
 * 另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的
 * 和 ，其中 left <= right
 *
 *
 * 实现 NumArray 类：
 *
 *
 * NumArray(int[] nums) 用整数数组 nums 初始化对象
 * void update(int index, int val) 将 nums[index] 的值 更新 为 val
 * int sumRange(int left, int right)
 * 返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的
 * 和 （即，nums[left] + nums[left + 1], ..., nums[right]）
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * 输出：
 * [null, 9, null, 8]
 *
 * 解释：
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // 返回 1 + 3 + 5 = 9
 * numArray.update(1, 2);   // nums = [1,2,5]
 * numArray.sumRange(0, 2); // 返回 1 + 2 + 5 = 8
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -100 <= nums[i] <= 100
 * 0 <= index < nums.length
 * -100 <= val <= 100
 * 0 <= left <= right < nums.length
 * 调用 update 和 sumRange 方法次数不大于 3 * 10^4 
 *
 *
 */

// @lc code=start
// 分块做法
/*
class NumArray {
    public:
        vector<int> nums, sum;

        int size;

        NumArray(vector<int>& nums) {
            int n = nums.size();
            size = sqrt(n);
            sum.resize((n + size - 1) / size);
            this->nums = nums;
            for (int i = 0; i < n; i++) {
                sum[i / size] += nums[i];
            }
        }

        void update(int index, int val) {
            sum[index / size] += val - nums[index];
            nums[index] = val;
        }

        int sumRange(int left, int right) {
            int idx1 = left / size;
            int idx2 = right / size;
            int i1 = left % size;
            int i2 = right % size;
            if (idx1 == idx2) {
                return accumulate(nums.begin() + idx1 * size + i1,
                                  nums.begin() + idx2 * size + i2 + 1, 0);
            }
            int sum1 = accumulate(nums.begin() + idx1 * size + i1,
                                  nums.begin() + (idx1 + 1) * size, 0);
            int sum2 = accumulate(nums.begin() + idx2 * size,
                                  nums.begin() + idx2 * size + i2 + 1, 0);
            int sum3 =
                accumulate(sum.begin() + idx1 + 1, sum.begin() + idx2, 0);
            return sum1 + sum2 + sum3;
        }
};
*/

// 线段树做法
class NumArray {
        struct Node {
                int l, r;
                int sum;
        };

        class SegmentTree {
            public:
                vector<Node> t;
                vector<int>  nums;

                SegmentTree() {}

                SegmentTree(vector<int>& nums) {
                    int n = nums.size();
                    t.resize(4 * n);
                    this->nums = nums;
                    build(1, 0, n - 1);
                }

                void pushup(int p, int l, int r) {
                    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
                }

                void build(int p, int l, int r) {
                    t[p] = {l, r};
                    if (l == r) {
                        t[p].sum = nums[l];
                        return;
                    }

                    int mid = (l + r) >> 1;
                    build(p << 1, l, mid);
                    build(p << 1 | 1, mid + 1, r);
                    pushup(p, l, r);
                }

                void update(int p, int idx, int val) {
                    if (t[p].l == t[p].r) {
                        t[p].sum = val;
                        return;
                    }

                    int mid = (t[p].l + t[p].r) >> 1;
                    if (idx <= mid) {
                        update(p << 1, idx, val);
                    } else {
                        update(p << 1 | 1, idx, val);
                    }
                    pushup(p, t[p].l, t[p].r);
                }

                int ask(int p, int l, int r) {
                    if (l <= t[p].l && t[p].r <= r) {
                        return t[p].sum;
                    }
                    int ans = 0;
                    int mid = (t[p].l + t[p].r) >> 1;
                    if (mid >= l) {
                        ans += ask(p << 1, l, r);
                    }
                    if (mid < r) {
                        ans += ask(p << 1 | 1, l, r);
                    }

                    return ans;
                }
        };

    public:
        SegmentTree a;

        NumArray(vector<int>& nums) {
            int n = nums.size();

            this->a = SegmentTree(nums);
        }

        void update(int index, int val) { a.update(1, index, val); }

        int sumRange(int left, int right) { return a.ask(1, left, right); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
