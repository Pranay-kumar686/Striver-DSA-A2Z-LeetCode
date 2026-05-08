class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
                vector<bool> isp(maxVal + 1, true);
        isp[0] = isp[1] = false;
        for (int i = 2; i * i <= maxVal; i++)
            if (isp[i])
                for (int j = i*i; j <= maxVal; j += i)
                    isp[j] = false;

        unordered_map<int, vector<int>> pm;
        for (int i = 0; i < n; i++)
            for (int p = 2; p * p <= nums[i]; p++)
                if (nums[i] % p == 0 && isp[p]) {
                    pm[p].push_back(i);
                    while (nums[i] % p == 0); 
                }
        pm.clear();
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            for (int p = 2; p * p <= v; p++)
                if (v % p == 0 && isp[p]) {
                    pm[p].push_back(i);
                    while (v % p == 0) v /= p;
                }
            if (v > 1) pm[v].push_back(i);
        }

        vector<bool> vis(n, false);
        unordered_set<int> used;
        queue<int> q;
        q.push(0); vis[0] = true;

        for (int steps = 0; !q.empty(); steps++) {
            for (int sz = q.size(); sz--;) {
                int i = q.front(); q.pop();
                if (i == n-1) return steps;
                for (int ni : {i-1, i+1})
                    if (ni >= 0 && ni < n && !vis[ni])
                        vis[ni] = true, q.push(ni);
                if (isp[nums[i]] && !used.count(nums[i])) {
                    used.insert(nums[i]);
                    for (int j : pm[nums[i]])
                        if (!vis[j]) vis[j] = true, q.push(j);
                }
            }
        }
        return -1;
    }
};