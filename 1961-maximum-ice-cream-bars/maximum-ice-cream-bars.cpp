class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = 0;
        for (int cost : costs)
            maxCost = max(maxCost, cost);
        vector<int> freq(maxCost + 1, 0);
        for (int cost : costs)
            freq[cost]++;
        int bars = 0;
        for (int price = 1; price <= maxCost && coins >= price; price++) {
            if (freq[price] == 0) continue;
            int canBuy = min(freq[price], coins / price);
            bars += canBuy;
            coins -= canBuy * price;
        }
        return bars;
    }
};