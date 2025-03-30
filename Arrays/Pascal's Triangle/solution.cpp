class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows, vector<int>());
        dp[0].push_back({1});
        for (int i = 1; i < numRows; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    dp[i].push_back(1);
                    continue;
                }
                dp[i].push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
            }
        }
        return dp;
    }
};