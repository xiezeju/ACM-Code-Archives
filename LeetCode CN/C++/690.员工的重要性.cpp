/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 *
 * https://leetcode.cn/problems/employee-importance/description/
 *
 * algorithms
 * Medium (65.82%)
 * Likes:    286
 * Dislikes: 0
 * Total Accepted:    66.9K
 * Total Submissions: 101.5K
 * Testcase Example:  '[[1,5,[2,3]],[2,3,[]],[3,3,[]]]\n1'
 *
 * 给定一个保存员工信息的数据结构，它包含了员工 唯一的 id ，重要度 和 直系下属的
 * id 。
 *
 * 比如，员工 1 是员工 2 的领导，员工 2 是员工 3 的领导。他们相应的重要度为 15 ,
 * 10 , 5 。那么员工 1 的数据结构是 [1, 15, [2]] ，员工 2的 数据结构是 [2, 10,
 * [3]] ，员工 3 的数据结构是 [3, 5, []] 。注意虽然员工 3 也是员工 1
 * 的一个下属，但是由于 并不是直系 下属，因此没有体现在员工 1 的数据结构中。
 *
 * 现在输入一个公司的所有员工信息，以及单个员工 id
 * ，返回这个员工和他所有下属的重要度之和。
 *
 *
 *
 * 示例：
 *
 *
 * 输入：[[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
 * 输出：11
 * 解释：
 * 员工 1 自身的重要度是 5 ，他有两个直系下属 2 和 3 ，而且 2 和 3 的重要度均为
 * 3 。因此员工 1 的总重要度是 5 + 3 + 3 = 11 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 一个员工最多有一个 直系 领导，但是可以有多个 直系 下属
 * 员工数量不超过 2000 。
 *
 *
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    public:
        unordered_map<int, Employee*> m;

        int dfs(Employee* employee) {
            if (employee->subordinates.size() == 0) {
                return employee->importance;
            }
            int sum = employee->importance;
            for (auto& id : employee->subordinates) {
                sum += dfs(m[id]);
            }
            return sum;
        }

        int getImportance(vector<Employee*> employees, int id) {
            for (auto& employee : employees) {
                m[employee->id] = employee;
            }
            return dfs(m[id]);
        }
};

// @lc code=end
