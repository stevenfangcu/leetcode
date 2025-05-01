/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
public:
    int k,m,n = 0;
    bool exist(vector<vector<char>> &board, string word)
    {
        k = word.length();
        m = board.size();
        n = board[0].size();
        unordered_set<string> visited;

    }
    bool backtrack(int row, int col, int position, int cpos)
    {
        if(k == position)
        {
            return true;
        }
        if(row < 0 || row )
    }       
};
// @lc code=end
