/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 *
 * [1146] 快照数组
 *
 * https://leetcode.cn/problems/snapshot-array/description/
 *
 * algorithms
 * Medium (33.74%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    10.2K
 * Total Submissions: 30.3K
 * Testcase Example:
 * '["SnapshotArray","set","snap","set","get"]\n[[3],[0,5],[],[0,6],[0,0]]'
 *
 * 实现支持下列接口的「快照数组」- SnapshotArray：
 *
 *
 * SnapshotArray(int length) - 初始化一个与指定长度相等的 类数组
 * 的数据结构。初始时，每个元素都等于 0。 void set(index, val) -
 * 会将指定索引 index 处的元素设置为 val。 int snap() -
 * 获取该数组的快照，并返回快照的编号 snap_id（快照号是调用 snap() 的总次数减去 1）。
 * int get(index, snap_id) - 根据指定的 snap_id 选择快照，并返回该快照指定索引
 * index 的值。
 *
 *
 *
 *
 * 示例：
 *
 * 输入：["SnapshotArray","set","snap","set","get"]
 * ⁠    [[3],[0,5],[],[0,6],[0,0]]
 * 输出：[null,null,0,null,5]
 * 解释：
 * SnapshotArray snapshotArr = new SnapshotArray(3); // 初始化一个长度为 3
 * 的快照数组 snapshotArr.set(0,5);  // 令 array[0] = 5 snapshotArr.snap();  //
 * 获取快照，返回 snap_id = 0 snapshotArr.set(0,6); snapshotArr.get(0,0);  //
 * 获取 snap_id = 0 的快照中 array[0] 的值，返回 5
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= length <= 50000
 * 题目最多进行50000 次set，snap，和 get的调用 。
 * 0 <= index < length
 * 0 <= snap_id < 我们调用 snap() 的总次数
 * 0 <= val <= 10^9
 *
 *
 */

// @lc code=start
class SnapshotArray {
    public:
        int snap_id = 0;

        vector<vector<pair<int, int>>> a;

        SnapshotArray(int length) { a.resize(length); }

        void set(int index, int val) { a[index].emplace_back(snap_id, val); }

        int snap() { return snap_id++; }

        int get(int index, int snap_id) {
            auto& snapVec = a[index];
            int   n = snapVec.size();
            if (n == 0) {
                return 0;
            }
            int l = 0, r = n;
            while (l < r) {
                int mid = l + r >> 1;
                if (snap_id < snapVec[mid].first) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l <= 0) {
                return 0;
            }
            return snapVec[l - 1].second;
        }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end
