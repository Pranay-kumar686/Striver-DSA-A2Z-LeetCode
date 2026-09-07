class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        int size=flowerbed.size();
        if(n==0) return true;
        for(int i=0; i<size; i++){
            if(flowerbed[i] == 0){
                int left= (i == 0) ? 0 : flowerbed[i-1];
                int right= (i == size-1) ? 0 : flowerbed[i+1];
                if(left == 0 && right == 0){
                    flowerbed[i]=1;
                    cnt++;
                    i++;
                }
            }
            if(cnt >= n) return true;
        }
        return cnt >= n;
    }
};