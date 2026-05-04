class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % k != 0) continue;

            int g = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] % k != 0) break;

                g = __gcd(g, nums[j]);

                if (g == k) ans++;
                else if (g < k) break;
            }
        }

        return ans;
    }
};