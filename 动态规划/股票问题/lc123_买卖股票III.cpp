//�޶����ν��� 

class Solution {
public:
    // dp[i][k][0]����i�죬�Ѿ�����k�Σ�Ŀǰû�й�Ʊʱ���е�Ǯ
    // dp[i][k][1]����i�죬�Ѿ�����k�Σ�Ŀǰ�й�Ʊʱ���е�Ǯ

   
    // dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
    // dp[i][1][1] = max(dp[i-1][1][1], -prices[i])
     // dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i])
    // dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i])
    
    int maxProfit(vector<int>& prices) {
        int dp_i10,dp_i11,dp_i20,dp_i21;
        dp_i10=dp_i20=0;
        dp_i11=dp_i21=INT_MIN;
        int tmp;
        for(int i=0;i<prices.size();i++){
            tmp=dp_i10;   //��ǰ��¼������ʹ��ǰ������
            dp_i10=max(dp_i10,dp_i11+prices[i]);
            dp_i11=max(dp_i11,-prices[i]);
            dp_i20=max(dp_i20,dp_i21+prices[i]);
            dp_i21=max(dp_i21,tmp-prices[i]);
        }
        return dp_i20;
    }
};
