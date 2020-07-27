// 无交易次数限制 


class Solution {
public:
    // dp[i][k][0]：第i天，已经交易k次，目前没有股票时持有的钱
    // dp[i][k][1]：第i天，已经交易k次，目前有股票时持有的钱
    
    // dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
    // dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
    // 由于只跟上一步有关系，因此数组空间上可以优化

    int maxProfit(vector<int>& prices) {
        int dp_i0=0,dp_i1=INT_MIN;
        int tmp;
        for(int i=0;i<prices.size();i++){
            tmp=dp_i0;
            dp_i0=max(dp_i0,dp_i1+prices[i]);
            dp_i1=max(dp_i1,tmp-prices[i]);
        }
        return dp_i0;
    }
};
