/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n-1;
        while(left <= right)
        {
            int middle = left+(right-left) / 2;
            int rows = middle/n;
            int col = middle%n;
            if(matrix[rows][col] == target)
            {
                return true;
            }
            else if (matrix[rows][col] < target)
            {
                left = middle + 1;
            }
            else 
            {
                right = middle - 1;
            }
        }
        return false;
    }
};
// @lc code=end

