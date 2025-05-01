/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();
        int counter = 2;
        for (int i = 2; i < nums.size(); ++i)
        {
            if (nums[i] != nums[counter - 2])
            {
                nums[counter] = nums[i];
                counter++;
            }
        }
        return counter;
    }
};
// @lc code=end
