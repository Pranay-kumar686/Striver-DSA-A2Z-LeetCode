class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        bitset<201> saw;
        bool dup = 0;

        for (auto& num : nums) {
            if (num > n) return false;

            if (saw.test(num)) {
                if (num < n || dup) return false;
                dup |= 1;
                continue;
            }

            saw.set(num);
        }

        return true;
    }
};