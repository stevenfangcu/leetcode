/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a hash map to store the sorted string as the key and 
        // the list of anagrams as the value
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        for(auto x: strs)
        {
            string word = x;
            sort(word.begin(), word.end());
            anagramMap[word].push_back(x);;
        }
        vector<vector<string>> res;
        for(auto y: anagramMap)
        {
            res.push_back(y.second);
        }
        return res;
    }
};
// @lc code=end

