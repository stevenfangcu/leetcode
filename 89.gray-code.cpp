/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        std::vector<int> res;
        n = 1 << n;
        for (int i = 0; i < n; ++i)
        {

            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};
// @lc code=end
