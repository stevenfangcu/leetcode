/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        if (s.empty()) return 0;
        int n = s.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
        }
        
        for(int len = 2; len <= n; ++len)
        {
            for(int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } 
                else
                {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end
