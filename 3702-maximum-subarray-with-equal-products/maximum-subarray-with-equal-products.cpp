class Solution {
    int gcd(int a, int b) {
        if(b) return gcd(b, a % b);
        return a;
    }
    int lcm(int a, int b) {
        return a/gcd(a, b)*b;
    }
public:
    int maxLength(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            unsigned long long gc = nums[i], lc = nums[i], pro = nums[i];
            for(int j=i+1; j<n; j++) {
                pro *= nums[j];
                gc = gcd(gc, nums[j]);
                lc = lcm(lc, nums[j]);
                if(pro == gc*lc) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};