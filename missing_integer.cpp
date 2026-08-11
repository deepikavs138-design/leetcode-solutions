class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];
        int i = 1;
        // Step 1: Find longest sequential prefix
        while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
            prefixSum += nums[i];
            i++;
        }
        // Step 2: Find smallest missing integer ≥ prefixSum
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = prefixSum;
        while (s.count(ans)) ans++;
        return ans;
    }
};
