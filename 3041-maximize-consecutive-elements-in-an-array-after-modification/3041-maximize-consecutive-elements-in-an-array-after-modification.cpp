class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> count(mx + 1, 0);

        for (int x : nums)
            count[x]++;

        vector<int> dp(mx + 2, 0);
        int answer = 0;

        for (int x = 1; x <= mx; x++) {
            if (count[x] == 0)
                continue;

            dp[x + 1] = max(dp[x + 1], dp[x] + 1);

            dp[x] = max(dp[x], dp[x - 1] + 1);

            if (count[x] > 1)
                dp[x + 1] = max(dp[x + 1], dp[x] + 1);

            answer = max({answer, dp[x], dp[x + 1]});
        }

        return answer;
    }
};