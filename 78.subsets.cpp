/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    void back(int start, vector<int> &nums, vector<int> &path, vector<vector<int>> &results)
    {
        results.push_back(path);
        for (int i = start; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            back(i + 1, nums, path, results);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        back(0, nums, path, res);
        return res;
    }
};
// @lc code=end
