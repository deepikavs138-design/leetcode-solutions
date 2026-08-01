#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: when there's only one number
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];

        // Fill DP table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        // If player1's score difference >= 0, player1 can win
        return dp[0][n - 1] >= 0;
    }
};
