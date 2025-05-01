/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
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
            if (i > start && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            back(i + 1, nums, path, results);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        back(0, nums, path, res);
        return res;
    }
};
// @lc code=end
