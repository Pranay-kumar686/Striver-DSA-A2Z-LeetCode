class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> bns(n, 0);
        //2345678
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && items[i][0] % items[j][0] == 0){
                    bns[j]++;
                }
            }
        }
        vector<int> dp(budget+1, 0);
        for(int i=0; i<n; i++){
            int cst=items[i][1];
            //zxcvbdfg
            int val=1+bns[i];
            for(int b=budget; b>=cst; b--){
                dp[b]=max(dp[b], dp[b-cst]+val);
            }
            //0987sdfgntyu
        }
        int ress=0;
        for(int mskCst=0; mskCst <= budget; mskCst++){
            int prcsd=dp[mskCst];
            int remm=budget-mskCst;
            //0ijfg
            int cpst=INT_MAX;
            //xcvtvghb
            for(auto &x : items) cpst=min(cpst, x[1]);
            ress=max(ress, prcsd+remm/cpst);
        }
        //2345qwertasdfgcvb
        return ress;
    }
};